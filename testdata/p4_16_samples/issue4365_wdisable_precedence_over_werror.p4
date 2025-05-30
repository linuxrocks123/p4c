// Expect no errors, as --Wdisable should take precedence over --Werror for warnings.
@command_line("--Werror", "--Wdisable=uninitialized_use", "--Wdisable=invalid_header")
header h_t {
    bit<28> f1;
    bit<4> f2;
}

extern void __e(in bit<28> arg);

control C() {
    action foo() {
        h_t h;
        __e(h.f1);
    }

    table t {
        actions = { foo; }
        default_action = foo;
    }

    apply {
        t.apply();
    }
}

control proto();
package top(proto p);

top(C()) main;
