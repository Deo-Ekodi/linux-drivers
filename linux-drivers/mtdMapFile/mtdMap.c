// #include <linux/mtd/map.h>   // which header?
#include <linux/fs.h>


struct mtdinfo* do_map_probe(char* name, struct map_info* map);

struct map_info{
    char* name;
    unsigned long size;
    unsigned long phys;

    #define NO_XIP (-1L)
    
    // void __iomem* virt;  // __iomem
    void* cached;

    int bandwidth;
    #ifdef CONFIG_MTD_COMPLEX_MAPPINGS
    // map_word (*read) (struct map_info*, unsigned long); // map_word
    void (*copy_from) (struct map_info*, void*, unsigned long, __kernel_ssize_t);

    void (*write) (struct map_info*, const map_word, unsigned long);
    void (*copy_to) (struct map_info*, unsigned long, const void*, __kernel_ssize_t);
    #endif

    void (*inval_cache) (struct map_info*, unsigned long, __kernel_size_t);
    void (*set_vpp) (struct map_info*, int);

    unsigned long map_priv_1;
    unsigned long map_priv_2;
    void* fldrv_priv;
    struct mtd_chip_driver* fldrv;
};

int add_mtd_partitions(struct mtdinfo* /*returned by do_map_probe()*/, struct mtd_partition*, int);
struct mtd_partition{};

