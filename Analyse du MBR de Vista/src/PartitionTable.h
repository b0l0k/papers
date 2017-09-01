struct PARTITION_DESCRIPTOR {
    unsigned char ACTIVE;
    unsigned char START_HEAD;
    unsigned char START_SEC;
    unsigned char START_CYL;
    unsigned char TYPE;
    unsigned char END_HEAD;
    unsigned char END_SEC;
    unsigned char END_CYL;
    unsigned int  START;
    unsigned int  SIZE;
};

struct PARTITION_TABLE {
    struct PARTITION_DESCRIPTOR ENTRIES[4];
};
