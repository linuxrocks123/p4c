%{
#define YY_USER_ACTION                                                          \
    { auto tmp = sources->getCurrentPosition();                                 \
      sources->appendText(yytext);                                              \
      yylloc = Util::SourceInfo(sources, tmp, sources->getCurrentPosition()); }

// shut up warnings about unused functions and variables
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wsign-compare"
#ifdef __clang__
#pragma clang diagnostic ignored "-Wnull-conversion"
#pragma clang diagnostic ignored "-Wregister"
#endif


static int              block_depth;
static std::string      block_buffer;
static YYLTYPE          block_start;
static std::string      comment_block;


%}

%option noyywrap nounput noinput noyyget_leng
%option noyyget_debug noyyset_debug noyyget_extra noyyset_extra noyyget_in noyyset_in
%option noyyget_out noyyset_out noyyget_text noyyget_lineno noyyset_lineno
%option stack

%x COMMENT EMIT CODEBLOCK
%s NORMAL PARSE_BRACKET PARSE_CTOR_INIT

%%

[ \t\r]+        ;
[\n]            ;

"#emit"[ \t]*[\n]         { block_buffer.clear();
                            block_start = yylloc;
                            yylval.emit.impl = false;
                            yy_push_state(EMIT); }
"#emit_impl"[ \t]*[\n]    { block_buffer.clear();
                            block_start = yylloc;
                            yylval.emit.impl = true;
                            yy_push_state(EMIT); }
<EMIT>[ \t\n]             { block_buffer += yytext; }
<EMIT>#end[ \t]*[\n]      { yy_pop_state();
                            yylval.emit.block = block_buffer;
                            yylloc = block_start + yylloc;
                            return EMITBLOCK; }
<EMIT>.*                  { block_buffer += yytext; }

"#include".*[\n]          { yylval.str = cstring(yytext); return INCLUDE; }

"/*"            { comment_block.clear();
                  comment_block += yytext;
                  yy_push_state(COMMENT); }
<COMMENT>"*/"   { yy_pop_state();
                  comment_block += yytext;
                  yylval.str = cstring(comment_block);
                  return COMMENTBLOCK; }
<COMMENT>.      { comment_block += yytext; }
<COMMENT>[\n]   { comment_block += yytext; }

"//".*           { yylval.str = cstring(yytext); return COMMENTBLOCK; }

"::"            { return DBLCOL; }
"abstract"      { return ABSTRACT; }
"class"         { return CLASS; }
"const"         { return CONST; }
"default"       { return DEFAULT; }
"delete"        { return DELETE; }
"enum"          { return ENUM; }
"inline"        { return INLINE; }
"interface"     { return INTERFACE; }
"namespace"     { return NAMESPACE; }
"new"           { return NEW; }
"operator"      { return OPERATOR; }
"optional"      { return OPTIONAL; }
"private"       { return PRIVATE; }
"protected"     { return PROTECTED; }
"public"        { return PUBLIC; }
"static"        { return STATIC; }
"variant"       { return VARIANT; }
"virtual"       { return VIRTUAL; }
"NullOK"        { return NULLOK; }
"#apply"        { return APPLY; }
"#no"[a-zA-Z_]*    { yylval.str = cstring(yytext+3); return NO; }
"#nooperator==" { yylval.str = cstring(yytext+3); return NO; }
"0"             { yylval.str = cstring(yytext); return ZERO; }
-?[0-9]+        { yylval.str = cstring(yytext); return INTEGER; }

[A-Za-z_][A-Za-z0-9_]*  { yylval.str = cstring(yytext); return IDENTIFIER; }
\"(\\.|[^\\"])*\"       { yylval.str = cstring(yytext); return STRING; }
<PARSE_BRACKET>"{"      { BEGIN(NORMAL); return *yytext; }

"{"                     { block_buffer = yytext;
                          block_depth = 1;
                          block_start = yylloc;
                          yy_push_state(CODEBLOCK); }
<PARSE_CTOR_INIT>":"    { block_buffer = yytext;
                          block_depth = 0;
                          block_start = yylloc;
                          yy_push_state(CODEBLOCK); }
<CODEBLOCK>"}"          { block_buffer += *yytext;
                          if (--block_depth <= 0) {
                              yy_pop_state();
                              yylval.str = cstring(block_buffer);
                              yylloc = block_start + yylloc;
                              return BLOCK; } }
<CODEBLOCK>"{"          { block_buffer += *yytext; ++block_depth; }
<CODEBLOCK>.|\n         { block_buffer += *yytext; }

.               { return *yytext; }

%%
