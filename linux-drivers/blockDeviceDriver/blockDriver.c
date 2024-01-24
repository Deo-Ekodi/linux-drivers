#include <linux/fs.h>
#include <linux/gen_stats.h>

int register_blkdev(unsigned int /*major number*/, const char* /*device name*/); 
struct gendisk* alloc_disk(int minors);
// block queue registration
extern void blk_init_queue(request_fn_proc* /*queue handler*/, spinlock_t* /*lock accessing queue*/);  // pending i/o operations of device


// remove block device

void blk_cleanup_queue(request_queue_t*);
void put_disk(struct gendisk disk*);
int unregister_blkdev(unsigned int, const char*);
