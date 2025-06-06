#include <core.p4>
#define V1MODEL_VERSION 20180101
#include <v1model.p4>

struct mystruct1 {
    bit<4> a;
    bit<4> b;
}

struct mystruct2 {
    mystruct1 foo;
    bit<4>    a;
    bit<4>    b;
}

enum myenum1 {
    MY_ENUM1_VAL1,
    MY_ENUM1_VAL2,
    MY_ENUM1_VAL3
}

header Ethernet_h {
    bit<48> dstAddr;
    bit<48> srcAddr;
    bit<16> etherType;
}

struct tuple_0 {
    bit<8>  f0;
    bit<16> f1;
}

struct myStruct1 {
    bit<7>        x1;
    int<33>       x2;
    bit<48>       x3;
    int<32>       x4;
    varbit<56>    x5;
    varbit<104>   x6;
    error         x7;
    bool          x8;
    myenum1       x9;
    Ethernet_h    x10;
    Ethernet_h[4] x11;
    mystruct1     x12;
    mystruct2     x13;
    tuple_0       x14;
}

