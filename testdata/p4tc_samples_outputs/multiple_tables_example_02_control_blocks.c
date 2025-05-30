#include "multiple_tables_example_02_parser.h"
struct p4tc_filter_fields p4tc_filter_fields;

struct internal_metadata {
    __u16 pkt_ether_type;
} __attribute__((aligned(4)));

struct skb_aggregate {
    struct p4tc_skb_meta_get get;
    struct p4tc_skb_meta_set set;
};

struct __attribute__((__packed__)) MainControlImpl_ipv4_tbl_1_key {
    u32 keysz;
    u32 maskid;
    u32 field0; /* hdr.ipv4.dstAddr */
} __attribute__((aligned(8)));
#define MAINCONTROLIMPL_IPV4_TBL_1_ACT_MAINCONTROLIMPL_NEXT_HOP 1
#define MAINCONTROLIMPL_IPV4_TBL_1_ACT_MAINCONTROLIMPL_DEFAULT_ROUTE_DROP 2
#define MAINCONTROLIMPL_IPV4_TBL_1_ACT_NOACTION 0
struct __attribute__((__packed__)) MainControlImpl_ipv4_tbl_1_value {
    unsigned int action;
    u32 hit:1,
    is_default_miss_act:1,
    is_default_hit_act:1;
    union {
        struct {
        } _NoAction;
        struct __attribute__((__packed__)) {
            u32 vport;
        } MainControlImpl_next_hop;
        struct {
        } MainControlImpl_default_route_drop;
    } u;
};
struct __attribute__((__packed__)) MainControlImpl_ipv4_tbl_2_key {
    u32 keysz;
    u32 maskid;
    u32 field0; /* hdr.ipv4.dstAddr */
    u32 field1; /* hdr.ipv4.srcAddr */
    u8 field2; /* hdr.ipv4.protocol */
} __attribute__((aligned(8)));
#define MAINCONTROLIMPL_IPV4_TBL_2_ACT_MAINCONTROLIMPL_NEXT_HOP 1
#define MAINCONTROLIMPL_IPV4_TBL_2_ACT_MAINCONTROLIMPL_DROP 4
#define MAINCONTROLIMPL_IPV4_TBL_2_ACT_NOACTION 0
struct __attribute__((__packed__)) MainControlImpl_ipv4_tbl_2_value {
    unsigned int action;
    u32 hit:1,
    is_default_miss_act:1,
    is_default_hit_act:1;
    union {
        struct {
        } _NoAction;
        struct __attribute__((__packed__)) {
            u32 vport;
        } MainControlImpl_next_hop;
        struct {
        } MainControlImpl_drop;
    } u;
};
struct __attribute__((__packed__)) MainControlImpl_ipv4_tbl_3_key {
    u32 keysz;
    u32 maskid;
    u32 field0; /* hdr.ipv4.dstAddr */
    u32 field1; /* hdr.ipv4.srcAddr */
    u8 field2; /* hdr.ipv4.flags */
} __attribute__((aligned(8)));
#define MAINCONTROLIMPL_IPV4_TBL_3_ACT_MAINCONTROLIMPL_SENDTOPORT 3
#define MAINCONTROLIMPL_IPV4_TBL_3_ACT_MAINCONTROLIMPL_DROP 4
#define MAINCONTROLIMPL_IPV4_TBL_3_ACT__NOACTION 0
struct __attribute__((__packed__)) MainControlImpl_ipv4_tbl_3_value {
    unsigned int action;
    u32 hit:1,
    is_default_miss_act:1,
    is_default_hit_act:1;
    union {
        struct {
        } _NoAction;
        struct {
        } MainControlImpl_sendtoport;
        struct {
        } MainControlImpl_drop;
    } u;
};
struct __attribute__((__packed__)) MainControlImpl_ipv4_tbl_4_key {
    u32 keysz;
    u32 maskid;
    u32 field0; /* hdr.ipv4.dstAddr */
    u32 field1; /* hdr.ipv4.srcAddr */
    u16 field2; /* hdr.ipv4.fragOffset */
} __attribute__((aligned(8)));
#define MAINCONTROLIMPL_IPV4_TBL_4_ACT_MAINCONTROLIMPL_SENDTOPORT 3
#define MAINCONTROLIMPL_IPV4_TBL_4_ACT_MAINCONTROLIMPL_DROP 4
#define MAINCONTROLIMPL_IPV4_TBL_4_ACT__NOACTION 0
struct __attribute__((__packed__)) MainControlImpl_ipv4_tbl_4_value {
    unsigned int action;
    u32 hit:1,
    is_default_miss_act:1,
    is_default_hit_act:1;
    union {
        struct {
        } _NoAction;
        struct {
        } MainControlImpl_sendtoport;
        struct {
        } MainControlImpl_drop;
    } u;
};
struct __attribute__((__packed__)) MainControlImpl_ipv4_tbl_5_key {
    u32 keysz;
    u32 maskid;
    u16 field0; /* hdr.ipv4.fragOffset */
} __attribute__((aligned(8)));
#define MAINCONTROLIMPL_IPV4_TBL_5_ACT__NOACTION 0
struct __attribute__((__packed__)) MainControlImpl_ipv4_tbl_5_value {
    unsigned int action;
    u32 hit:1,
    is_default_miss_act:1,
    is_default_hit_act:1;
    union {
        struct {
        } _NoAction;
    } u;
};
struct __attribute__((__packed__)) MainControlImpl_set_all_options_key {
    u32 keysz;
    u32 maskid;
    u32 field0; /* hdr.ipv4.srcAddr */
    u16 field1; /* hdr.tcp.srcPort */
    u16 field2; /* hdr.ipv4.fragOffset */
    u8 field3; /* hdr.ipv4.flags */
} __attribute__((aligned(8)));
#define MAINCONTROLIMPL_SET_ALL_OPTIONS_ACT_MAINCONTROLIMPL_NEXT_HOP 1
#define MAINCONTROLIMPL_SET_ALL_OPTIONS_ACT_MAINCONTROLIMPL_DEFAULT_ROUTE_DROP 2
#define MAINCONTROLIMPL_SET_ALL_OPTIONS_ACT_MAINCONTROLIMPL_TCP_SYN_PACKET 5
#define MAINCONTROLIMPL_SET_ALL_OPTIONS_ACT_MAINCONTROLIMPL_TCP_FIN_OR_RST_PACKET 6
#define MAINCONTROLIMPL_SET_ALL_OPTIONS_ACT_MAINCONTROLIMPL_TCP_OTHER_PACKETS 7
#define MAINCONTROLIMPL_SET_ALL_OPTIONS_ACT_MAINCONTROLIMPL_SENDTOPORT 3
#define MAINCONTROLIMPL_SET_ALL_OPTIONS_ACT_MAINCONTROLIMPL_DROP 4
#define MAINCONTROLIMPL_SET_ALL_OPTIONS_ACT__NOACTION 0
struct __attribute__((__packed__)) MainControlImpl_set_all_options_value {
    unsigned int action;
    u32 hit:1,
    is_default_miss_act:1,
    is_default_hit_act:1;
    union {
        struct {
        } _NoAction;
        struct __attribute__((__packed__)) {
            u32 vport;
        } MainControlImpl_next_hop;
        struct {
        } MainControlImpl_default_route_drop;
        struct {
        } MainControlImpl_tcp_syn_packet;
        struct {
        } MainControlImpl_tcp_fin_or_rst_packet;
        struct {
        } MainControlImpl_tcp_other_packets;
        struct {
        } MainControlImpl_sendtoport;
        struct {
        } MainControlImpl_drop;
    } u;
};
struct __attribute__((__packed__)) MainControlImpl_set_ct_options_key {
    u32 keysz;
    u32 maskid;
    u8 field0; /* hdr.tcp.flags */
} __attribute__((aligned(8)));
#define MAX_MAINCONTROLIMPL_SET_CT_OPTIONS_KEY_MASKS 128
struct MainControlImpl_set_ct_options_key_mask {
    __u8 mask[sizeof(struct MainControlImpl_set_ct_options_key)];
} __attribute__((aligned(8)));
#define MAINCONTROLIMPL_SET_CT_OPTIONS_ACT_MAINCONTROLIMPL_TCP_SYN_PACKET 5
#define MAINCONTROLIMPL_SET_CT_OPTIONS_ACT_MAINCONTROLIMPL_TCP_FIN_OR_RST_PACKET 6
#define MAINCONTROLIMPL_SET_CT_OPTIONS_ACT_MAINCONTROLIMPL_TCP_OTHER_PACKETS 7
#define MAINCONTROLIMPL_SET_CT_OPTIONS_ACT_NOACTION 0
struct __attribute__((__packed__)) MainControlImpl_set_ct_options_value {
    unsigned int action;
    u32 hit:1,
    is_default_miss_act:1,
    is_default_hit_act:1;
    union {
        struct {
        } _NoAction;
        struct {
        } MainControlImpl_tcp_syn_packet;
        struct {
        } MainControlImpl_tcp_fin_or_rst_packet;
        struct {
        } MainControlImpl_tcp_other_packets;
    } u;
};

static __always_inline int process(struct __sk_buff *skb, struct headers_t *hdr, struct pna_global_metadata *compiler_meta__, struct skb_aggregate *sa)
{
    struct hdr_md *hdrMd;

    unsigned ebpf_packetOffsetInBits_save = 0;
    ParserError_t ebpf_errorCode = NoError;
    void* pkt = ((void*)(long)skb->data);
    u8* hdr_start = pkt;
    void* ebpf_packetEnd = ((void*)(long)skb->data_end);
    u32 ebpf_zero = 0;
    u32 ebpf_one = 1;
    unsigned char ebpf_byte;
    u32 pkt_len = skb->len;

    struct main_metadata_t *user_meta;
    hdrMd = BPF_MAP_LOOKUP_ELEM(hdr_md_cpumap, &ebpf_zero);
    if (!hdrMd)
        return TC_ACT_SHOT;
    unsigned ebpf_packetOffsetInBits = hdrMd->ebpf_packetOffsetInBits;
    hdr_start = pkt + BYTES(ebpf_packetOffsetInBits);
    hdr = &(hdrMd->cpumap_hdr);
    user_meta = &(hdrMd->cpumap_usermeta);
{
        u8 hit;
        {
if (/* hdr->ipv4.isValid() */
            hdr->ipv4.ebpf_valid) {
/* ipv4_tbl.apply() */
                {
                    /* construct key */
                    struct p4tc_table_entry_act_bpf_params__local params = {
                        .pipeid = p4tc_filter_fields.pipeid,
                        .tblid = 1
                    };
                    struct MainControlImpl_ipv4_tbl_1_key key;
                    __builtin_memset(&key, 0, sizeof(key));
                    key.keysz = 32;
                    key.field0 = hdr->ipv4.dstAddr;
                    struct p4tc_table_entry_act_bpf *act_bpf;
                    /* value */
                    struct MainControlImpl_ipv4_tbl_1_value *value = NULL;
                    /* perform lookup */
                    act_bpf = bpf_p4tc_tbl_read(skb, &params, sizeof(params), &key, sizeof(key));
                    value = (struct MainControlImpl_ipv4_tbl_1_value *)act_bpf;
                    if (value == NULL) {
                        /* miss; find default action */
                        hit = 0;
                    } else {
                        hit = value->hit;
                    }
                    if (value != NULL) {
                        /* run action */
                        switch (value->action) {
                            case MAINCONTROLIMPL_IPV4_TBL_1_ACT_MAINCONTROLIMPL_NEXT_HOP: 
                                {
                                    hdr->ipv4.version = 1;
                                    /* send_to_port(value->u.MainControlImpl_next_hop.vport) */
                                    compiler_meta__->drop = false;
                                    send_to_port(value->u.MainControlImpl_next_hop.vport);
                                }
                                break;
                            case MAINCONTROLIMPL_IPV4_TBL_1_ACT_MAINCONTROLIMPL_DEFAULT_ROUTE_DROP: 
                                {
if (hdr->ipv4.protocol != 6) {
/* drop_packet() */
                                        drop_packet();                                    }

                                }
                                break;
                            case MAINCONTROLIMPL_IPV4_TBL_1_ACT_NOACTION: 
                                {
                                }
                                break;
                        }
                    } else {
                    }
                }
;
                /* ipv4_tbl_0.apply() */
                {
                    /* construct key */
                    struct p4tc_table_entry_act_bpf_params__local params = {
                        .pipeid = p4tc_filter_fields.pipeid,
                        .tblid = 2
                    };
                    struct MainControlImpl_ipv4_tbl_2_key key;
                    __builtin_memset(&key, 0, sizeof(key));
                    key.keysz = 72;
                    key.field0 = hdr->ipv4.dstAddr;
                    key.field1 = hdr->ipv4.srcAddr;
                    key.field2 = hdr->ipv4.protocol;
                    struct p4tc_table_entry_act_bpf *act_bpf;
                    /* value */
                    struct MainControlImpl_ipv4_tbl_2_value *value = NULL;
                    /* perform lookup */
                    act_bpf = bpf_p4tc_tbl_read(skb, &params, sizeof(params), &key, sizeof(key));
                    value = (struct MainControlImpl_ipv4_tbl_2_value *)act_bpf;
                    if (value == NULL) {
                        /* miss; find default action */
                        hit = 0;
                    } else {
                        hit = value->hit;
                    }
                    if (value != NULL) {
                        /* run action */
                        switch (value->action) {
                            case MAINCONTROLIMPL_IPV4_TBL_2_ACT_MAINCONTROLIMPL_NEXT_HOP: 
                                {
                                    hdr->ipv4.version = 1;
                                    /* send_to_port(value->u.MainControlImpl_next_hop.vport) */
                                    compiler_meta__->drop = false;
                                    send_to_port(value->u.MainControlImpl_next_hop.vport);
                                }
                                break;
                            case MAINCONTROLIMPL_IPV4_TBL_2_ACT_MAINCONTROLIMPL_DROP: 
                                {
if (hdr->ipv4.protocol == 6 || ((hdr->ipv4.version > 1) && (hdr->ipv4.ihl <= 2))) {
/* drop_packet() */
                                        drop_packet();                                    }

                                }
                                break;
                            case MAINCONTROLIMPL_IPV4_TBL_2_ACT_NOACTION: 
                                {
                                }
                                break;
                        }
                    } else {
                    }
                }
;
                /* ipv4_tbl_6.apply() */
                {
                    /* construct key */
                    struct p4tc_table_entry_act_bpf_params__local params = {
                        .pipeid = p4tc_filter_fields.pipeid,
                        .tblid = 3
                    };
                    struct MainControlImpl_ipv4_tbl_3_key key;
                    __builtin_memset(&key, 0, sizeof(key));
                    key.keysz = 67;
                    key.field0 = hdr->ipv4.dstAddr;
                    key.field1 = hdr->ipv4.srcAddr;
                    key.field2 = hdr->ipv4.flags;
                    struct p4tc_table_entry_act_bpf *act_bpf;
                    /* value */
                    struct MainControlImpl_ipv4_tbl_3_value *value = NULL;
                    /* perform lookup */
                    act_bpf = bpf_p4tc_tbl_read(skb, &params, sizeof(params), &key, sizeof(key));
                    value = (struct MainControlImpl_ipv4_tbl_3_value *)act_bpf;
                    if (value == NULL) {
                        /* miss; find default action */
                        hit = 0;
                    } else {
                        hit = value->hit;
                    }
                    if (value != NULL) {
                        /* run action */
                        switch (value->action) {
                            case MAINCONTROLIMPL_IPV4_TBL_3_ACT_MAINCONTROLIMPL_SENDTOPORT: 
                                {
/* send_to_port(skb->ifindex) */
                                    compiler_meta__->drop = false;
                                    send_to_port(skb->ifindex);
                                }
                                break;
                            case MAINCONTROLIMPL_IPV4_TBL_3_ACT_MAINCONTROLIMPL_DROP: 
                                {
if (hdr->ipv4.protocol == 6 || ((hdr->ipv4.version > 1) && (hdr->ipv4.ihl <= 2))) {
/* drop_packet() */
                                        drop_packet();                                    }

                                }
                                break;
                            case MAINCONTROLIMPL_IPV4_TBL_3_ACT__NOACTION: 
                                {
                                }
                                break;
                        }
                    } else {
                    }
                }
;
                /* ipv4_tbl_7.apply() */
                {
                    /* construct key */
                    struct p4tc_table_entry_act_bpf_params__local params = {
                        .pipeid = p4tc_filter_fields.pipeid,
                        .tblid = 4
                    };
                    struct MainControlImpl_ipv4_tbl_4_key key;
                    __builtin_memset(&key, 0, sizeof(key));
                    key.keysz = 77;
                    key.field0 = hdr->ipv4.dstAddr;
                    key.field1 = hdr->ipv4.srcAddr;
                    key.field2 = hdr->ipv4.fragOffset;
                    struct p4tc_table_entry_act_bpf *act_bpf;
                    /* value */
                    struct MainControlImpl_ipv4_tbl_4_value *value = NULL;
                    /* perform lookup */
                    act_bpf = bpf_p4tc_tbl_read(skb, &params, sizeof(params), &key, sizeof(key));
                    value = (struct MainControlImpl_ipv4_tbl_4_value *)act_bpf;
                    if (value == NULL) {
                        /* miss; find default action */
                        hit = 0;
                    } else {
                        hit = value->hit;
                    }
                    if (value != NULL) {
                        /* run action */
                        switch (value->action) {
                            case MAINCONTROLIMPL_IPV4_TBL_4_ACT_MAINCONTROLIMPL_SENDTOPORT: 
                                {
/* send_to_port(skb->ifindex) */
                                    compiler_meta__->drop = false;
                                    send_to_port(skb->ifindex);
                                }
                                break;
                            case MAINCONTROLIMPL_IPV4_TBL_4_ACT_MAINCONTROLIMPL_DROP: 
                                {
if (hdr->ipv4.protocol == 6 || ((hdr->ipv4.version > 1) && (hdr->ipv4.ihl <= 2))) {
/* drop_packet() */
                                        drop_packet();                                    }

                                }
                                break;
                            case MAINCONTROLIMPL_IPV4_TBL_4_ACT__NOACTION: 
                                {
                                }
                                break;
                        }
                    } else {
                    }
                }
;
                /* ipv4_tbl_8.apply() */
                {
                    /* construct key */
                    struct p4tc_table_entry_act_bpf_params__local params = {
                        .pipeid = p4tc_filter_fields.pipeid,
                        .tblid = 5
                    };
                    struct MainControlImpl_ipv4_tbl_5_key key;
                    __builtin_memset(&key, 0, sizeof(key));
                    key.keysz = 13;
                    key.field0 = hdr->ipv4.fragOffset;
                    struct p4tc_table_entry_act_bpf *act_bpf;
                    /* value */
                    struct MainControlImpl_ipv4_tbl_5_value *value = NULL;
                    /* perform lookup */
                    act_bpf = bpf_p4tc_tbl_read(skb, &params, sizeof(params), &key, sizeof(key));
                    value = (struct MainControlImpl_ipv4_tbl_5_value *)act_bpf;
                    if (value == NULL) {
                        /* miss; find default action */
                        hit = 0;
                    } else {
                        hit = value->hit;
                    }
                    if (value != NULL) {
                        /* run action */
                        switch (value->action) {
                            case MAINCONTROLIMPL_IPV4_TBL_5_ACT__NOACTION: 
                                {
                                }
                                break;
                        }
                    } else {
                    }
                }
;
                /* set_ct_options_0.apply() */
                {
                    /* construct key */
                    struct p4tc_table_entry_act_bpf_params__local params = {
                        .pipeid = p4tc_filter_fields.pipeid,
                        .tblid = 6
                    };
                    struct MainControlImpl_set_ct_options_key key;
                    __builtin_memset(&key, 0, sizeof(key));
                    key.keysz = 8;
                    key.field0 = hdr->tcp.flags;
                    struct p4tc_table_entry_act_bpf *act_bpf;
                    /* value */
                    struct MainControlImpl_set_ct_options_value *value = NULL;
                    /* perform lookup */
                    act_bpf = bpf_p4tc_tbl_read(skb, &params, sizeof(params), &key, sizeof(key));
                    value = (struct MainControlImpl_set_ct_options_value *)act_bpf;
                    if (value == NULL) {
                        /* miss; find default action */
                        hit = 0;
                    } else {
                        hit = value->hit;
                    }
                    if (value != NULL) {
                        /* run action */
                        switch (value->action) {
                            case MAINCONTROLIMPL_SET_CT_OPTIONS_ACT_MAINCONTROLIMPL_TCP_SYN_PACKET: 
                                {
                                }
                                break;
                            case MAINCONTROLIMPL_SET_CT_OPTIONS_ACT_MAINCONTROLIMPL_TCP_FIN_OR_RST_PACKET: 
                                {
                                }
                                break;
                            case MAINCONTROLIMPL_SET_CT_OPTIONS_ACT_MAINCONTROLIMPL_TCP_OTHER_PACKETS: 
                                {
                                }
                                break;
                            case MAINCONTROLIMPL_SET_CT_OPTIONS_ACT_NOACTION: 
                                {
                                }
                                break;
                        }
                    } else {
                    }
                }
;
                /* set_all_options_0.apply() */
                {
                    /* construct key */
                    struct p4tc_table_entry_act_bpf_params__local params = {
                        .pipeid = p4tc_filter_fields.pipeid,
                        .tblid = 7
                    };
                    struct MainControlImpl_set_all_options_key key;
                    __builtin_memset(&key, 0, sizeof(key));
                    key.keysz = 64;
                    key.field0 = hdr->ipv4.srcAddr;
                    key.field1 = hdr->tcp.srcPort;
                    key.field2 = hdr->ipv4.fragOffset;
                    key.field3 = hdr->ipv4.flags;
                    struct p4tc_table_entry_act_bpf *act_bpf;
                    /* value */
                    struct MainControlImpl_set_all_options_value *value = NULL;
                    /* perform lookup */
                    act_bpf = bpf_p4tc_tbl_read(skb, &params, sizeof(params), &key, sizeof(key));
                    value = (struct MainControlImpl_set_all_options_value *)act_bpf;
                    if (value == NULL) {
                        /* miss; find default action */
                        hit = 0;
                    } else {
                        hit = value->hit;
                    }
                    if (value != NULL) {
                        /* run action */
                        switch (value->action) {
                            case MAINCONTROLIMPL_SET_ALL_OPTIONS_ACT_MAINCONTROLIMPL_NEXT_HOP: 
                                {
                                    hdr->ipv4.version = 1;
                                    /* send_to_port(value->u.MainControlImpl_next_hop.vport) */
                                    compiler_meta__->drop = false;
                                    send_to_port(value->u.MainControlImpl_next_hop.vport);
                                }
                                break;
                            case MAINCONTROLIMPL_SET_ALL_OPTIONS_ACT_MAINCONTROLIMPL_DEFAULT_ROUTE_DROP: 
                                {
if (hdr->ipv4.protocol != 6) {
/* drop_packet() */
                                        drop_packet();                                    }

                                }
                                break;
                            case MAINCONTROLIMPL_SET_ALL_OPTIONS_ACT_MAINCONTROLIMPL_TCP_SYN_PACKET: 
                                {
                                }
                                break;
                            case MAINCONTROLIMPL_SET_ALL_OPTIONS_ACT_MAINCONTROLIMPL_TCP_FIN_OR_RST_PACKET: 
                                {
                                }
                                break;
                            case MAINCONTROLIMPL_SET_ALL_OPTIONS_ACT_MAINCONTROLIMPL_TCP_OTHER_PACKETS: 
                                {
                                }
                                break;
                            case MAINCONTROLIMPL_SET_ALL_OPTIONS_ACT_MAINCONTROLIMPL_SENDTOPORT: 
                                {
/* send_to_port(skb->ifindex) */
                                    compiler_meta__->drop = false;
                                    send_to_port(skb->ifindex);
                                }
                                break;
                            case MAINCONTROLIMPL_SET_ALL_OPTIONS_ACT_MAINCONTROLIMPL_DROP: 
                                {
if (hdr->ipv4.protocol == 6 || ((hdr->ipv4.version > 1) && (hdr->ipv4.ihl <= 2))) {
/* drop_packet() */
                                        drop_packet();                                    }

                                }
                                break;
                            case MAINCONTROLIMPL_SET_ALL_OPTIONS_ACT__NOACTION: 
                                {
                                }
                                break;
                        }
                    } else {
                    }
                }
;
            }
        }
    }
    {
{
;
            ;
        }

        if (compiler_meta__->drop) {
            return TC_ACT_SHOT;
        }
        int outHeaderLength = 0;
        if (hdr->ethernet.ebpf_valid) {
            outHeaderLength += 112;
        }
;        if (hdr->ipv4.ebpf_valid) {
            outHeaderLength += 160;
        }
;
        __u16 saved_proto = 0;
        bool have_saved_proto = false;
        // bpf_skb_adjust_room works only when protocol is IPv4 or IPv6
        // 0x0800 = IPv4, 0x86dd = IPv6
        if ((skb->protocol != bpf_htons(0x0800)) && (skb->protocol != bpf_htons(0x86dd))) {
            saved_proto = skb->protocol;
            have_saved_proto = true;
            bpf_p4tc_skb_set_protocol(skb, &sa->set, bpf_htons(0x0800));
            bpf_p4tc_skb_meta_set(skb, &sa->set, sizeof(sa->set));
        }
        ;

        int outHeaderOffset = BYTES(outHeaderLength) - (hdr_start - (u8*)pkt);
        if (outHeaderOffset != 0) {
            int returnCode = 0;
            returnCode = bpf_skb_adjust_room(skb, outHeaderOffset, 1, 0);
            if (returnCode) {
                return TC_ACT_SHOT;
            }
        }

        if (have_saved_proto) {
            bpf_p4tc_skb_set_protocol(skb, &sa->set, saved_proto);
            bpf_p4tc_skb_meta_set(skb, &sa->set, sizeof(sa->set));
        }

        pkt = ((void*)(long)skb->data);
        ebpf_packetEnd = ((void*)(long)skb->data_end);
        ebpf_packetOffsetInBits = 0;
        if (hdr->ethernet.ebpf_valid) {
            if (ebpf_packetEnd < pkt + BYTES(ebpf_packetOffsetInBits + 112)) {
                return TC_ACT_SHOT;
            }
            
            storePrimitive64((u8 *)&hdr->ethernet.dstAddr, 48, (htonll(getPrimitive64(hdr->ethernet.dstAddr, 48) << 16)));
            ebpf_byte = ((char*)(&hdr->ethernet.dstAddr))[0];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 0, (ebpf_byte));
            ebpf_byte = ((char*)(&hdr->ethernet.dstAddr))[1];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 1, (ebpf_byte));
            ebpf_byte = ((char*)(&hdr->ethernet.dstAddr))[2];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 2, (ebpf_byte));
            ebpf_byte = ((char*)(&hdr->ethernet.dstAddr))[3];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 3, (ebpf_byte));
            ebpf_byte = ((char*)(&hdr->ethernet.dstAddr))[4];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 4, (ebpf_byte));
            ebpf_byte = ((char*)(&hdr->ethernet.dstAddr))[5];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 5, (ebpf_byte));
            ebpf_packetOffsetInBits += 48;

            storePrimitive64((u8 *)&hdr->ethernet.srcAddr, 48, (htonll(getPrimitive64(hdr->ethernet.srcAddr, 48) << 16)));
            ebpf_byte = ((char*)(&hdr->ethernet.srcAddr))[0];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 0, (ebpf_byte));
            ebpf_byte = ((char*)(&hdr->ethernet.srcAddr))[1];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 1, (ebpf_byte));
            ebpf_byte = ((char*)(&hdr->ethernet.srcAddr))[2];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 2, (ebpf_byte));
            ebpf_byte = ((char*)(&hdr->ethernet.srcAddr))[3];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 3, (ebpf_byte));
            ebpf_byte = ((char*)(&hdr->ethernet.srcAddr))[4];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 4, (ebpf_byte));
            ebpf_byte = ((char*)(&hdr->ethernet.srcAddr))[5];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 5, (ebpf_byte));
            ebpf_packetOffsetInBits += 48;

            hdr->ethernet.etherType = bpf_htons(hdr->ethernet.etherType);
            ebpf_byte = ((char*)(&hdr->ethernet.etherType))[0];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 0, (ebpf_byte));
            ebpf_byte = ((char*)(&hdr->ethernet.etherType))[1];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 1, (ebpf_byte));
            ebpf_packetOffsetInBits += 16;

        }
;        if (hdr->ipv4.ebpf_valid) {
            if (ebpf_packetEnd < pkt + BYTES(ebpf_packetOffsetInBits + 160)) {
                return TC_ACT_SHOT;
            }
            
            ebpf_byte = ((char*)(&hdr->ipv4.version))[0];
            write_partial(pkt + BYTES(ebpf_packetOffsetInBits) + 0, 4, 4, (ebpf_byte >> 0));
            ebpf_packetOffsetInBits += 4;

            ebpf_byte = ((char*)(&hdr->ipv4.ihl))[0];
            write_partial(pkt + BYTES(ebpf_packetOffsetInBits) + 0, 4, 0, (ebpf_byte >> 0));
            ebpf_packetOffsetInBits += 4;

            ebpf_byte = ((char*)(&hdr->ipv4.diffserv))[0];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 0, (ebpf_byte));
            ebpf_packetOffsetInBits += 8;

            hdr->ipv4.totalLen = bpf_htons(hdr->ipv4.totalLen);
            ebpf_byte = ((char*)(&hdr->ipv4.totalLen))[0];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 0, (ebpf_byte));
            ebpf_byte = ((char*)(&hdr->ipv4.totalLen))[1];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 1, (ebpf_byte));
            ebpf_packetOffsetInBits += 16;

            hdr->ipv4.identification = bpf_htons(hdr->ipv4.identification);
            ebpf_byte = ((char*)(&hdr->ipv4.identification))[0];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 0, (ebpf_byte));
            ebpf_byte = ((char*)(&hdr->ipv4.identification))[1];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 1, (ebpf_byte));
            ebpf_packetOffsetInBits += 16;

            ebpf_byte = ((char*)(&hdr->ipv4.flags))[0];
            write_partial(pkt + BYTES(ebpf_packetOffsetInBits) + 0, 3, 5, (ebpf_byte >> 0));
            ebpf_packetOffsetInBits += 3;

            hdr->ipv4.fragOffset = bpf_htons(hdr->ipv4.fragOffset << 3);
            ebpf_byte = ((char*)(&hdr->ipv4.fragOffset))[0];
            write_partial(pkt + BYTES(ebpf_packetOffsetInBits) + 0, 5, 0, (ebpf_byte >> 3));
            write_partial(pkt + BYTES(ebpf_packetOffsetInBits) + 0 + 1, 3, 5, (ebpf_byte));
            ebpf_byte = ((char*)(&hdr->ipv4.fragOffset))[1];
            write_partial(pkt + BYTES(ebpf_packetOffsetInBits) + 1, 5, 0, (ebpf_byte >> 3));
            ebpf_packetOffsetInBits += 13;

            ebpf_byte = ((char*)(&hdr->ipv4.ttl))[0];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 0, (ebpf_byte));
            ebpf_packetOffsetInBits += 8;

            ebpf_byte = ((char*)(&hdr->ipv4.protocol))[0];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 0, (ebpf_byte));
            ebpf_packetOffsetInBits += 8;

            hdr->ipv4.hdrChecksum = bpf_htons(hdr->ipv4.hdrChecksum);
            ebpf_byte = ((char*)(&hdr->ipv4.hdrChecksum))[0];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 0, (ebpf_byte));
            ebpf_byte = ((char*)(&hdr->ipv4.hdrChecksum))[1];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 1, (ebpf_byte));
            ebpf_packetOffsetInBits += 16;

            ebpf_byte = ((char*)(&hdr->ipv4.srcAddr))[0];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 0, (ebpf_byte));
            ebpf_byte = ((char*)(&hdr->ipv4.srcAddr))[1];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 1, (ebpf_byte));
            ebpf_byte = ((char*)(&hdr->ipv4.srcAddr))[2];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 2, (ebpf_byte));
            ebpf_byte = ((char*)(&hdr->ipv4.srcAddr))[3];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 3, (ebpf_byte));
            ebpf_packetOffsetInBits += 32;

            ebpf_byte = ((char*)(&hdr->ipv4.dstAddr))[0];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 0, (ebpf_byte));
            ebpf_byte = ((char*)(&hdr->ipv4.dstAddr))[1];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 1, (ebpf_byte));
            ebpf_byte = ((char*)(&hdr->ipv4.dstAddr))[2];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 2, (ebpf_byte));
            ebpf_byte = ((char*)(&hdr->ipv4.dstAddr))[3];
            write_byte(pkt, BYTES(ebpf_packetOffsetInBits) + 3, (ebpf_byte));
            ebpf_packetOffsetInBits += 32;

        }
;
    }
    return -1;
}
SEC("p4tc/main")
int tc_ingress_func(struct __sk_buff *skb) {
    struct skb_aggregate skbstuff;
    struct pna_global_metadata *compiler_meta__ = (struct pna_global_metadata *) skb->cb;
    compiler_meta__->drop = false;
    compiler_meta__->recirculate = false;
    compiler_meta__->egress_port = 0;
    if (!compiler_meta__->recirculated) {
        compiler_meta__->mark = 153;
        struct internal_metadata *md = (struct internal_metadata *)(unsigned long)skb->data_meta;
        if ((void *) ((struct internal_metadata *) md + 1) <= (void *)(long)skb->data) {
            __u16 *ether_type = (__u16 *) ((void *) (long)skb->data + 12);
            if ((void *) ((__u16 *) ether_type + 1) > (void *) (long) skb->data_end) {
                return TC_ACT_SHOT;
            }
            *ether_type = md->pkt_ether_type;
        }
    }
    struct hdr_md *hdrMd;
    struct headers_t *hdr;
    int ret = -1;
    ret = process(skb, (struct headers_t *) hdr, compiler_meta__, &skbstuff);
    if (ret != -1) {
        return ret;
    }
    if (!compiler_meta__->drop && compiler_meta__->recirculate) {
        compiler_meta__->recirculated = true;
        return TC_ACT_UNSPEC;
    }
    if (!compiler_meta__->drop && compiler_meta__->egress_port == 0)
        return TC_ACT_OK;
    return bpf_redirect(compiler_meta__->egress_port, 0);
}
char _license[] SEC("license") = "GPL";
