#include <linux/fs.h>
#include <linux/fb.h>

int register_frabebuffer(struct fb_info*);

struct fb_info{
    int node;
    int flags;
    struct fb_var_screeninfo var;
    struct fb_fix_screeninfo fix;
    struct fb_monspecs monspecs;
    struct work_struct queue;
    struct fb_pixmap pixmap;
    struct pixmap sprite;
    struct fb_cmap cmap;
    struct list_head modelist;
    struct fb_ops* fbops;
    struct device* device;

    #ifdef CONFIG_FB_TILEBLITTIG
    struct fb_tile_ops* tiileops;
    #endif

    // char __iomem* screen_base;   // __iomem*
    unsigned long screen_size;
    void *pseudo_palette;

    #define FBINFO_STATE_RUNNING    0
    #define FBINFO_STATE_SUSPENDED  1

    __u32 state;
    void* fbcon_par;
    void* par;
};

struct fb_var_screeninfo {};
struct fb_fix_screeninfo {};
struct fb_monspecs {};
struct work_struct {};
struct fb_pixmap {};
struct pixmap {};
struct fb_cmap {};
struct list_head {};
struct fb_ops {};
struct device {};

// init
int register_frabebuffer(struct fb_info* fbinfo){return 0;}
int unregister_framebuffer(struct fb_info* fbinfo){return 0;}