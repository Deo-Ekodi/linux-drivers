#include <linux/fs.h>
#include <stdio.h>

// older way
int register_chrdev(unsigned/*major number*/, const char*/*device name*/, struct file_operations*);
int unregister_chrdrv(unsigned int, const char*);

struct file_operations{
    struct module* owner;
    __kernel_loff_t (*llseek) (struct file*, __kernel_loff_t, int);     /*set read/write position, return new position*/
    __kernel_ssize_t (*read) (struct file*, char* __user, __kernel_size_t, __kernel_loff_t);    /*read from device, if null -EINVAL, return how much data read*/
    __kernel_ssize_t (*aio_read) (struct kiocb*, char* __user, __kernel_size_t, __kernel_loff_t);   /*asynchronous read, if null normal read gets called*/
    __kernel_ssize_t (*write) (struct file*, const char __user*, __kernel_size_t, __kernel_loff_t);    /*write to device, if NULL -EINVAL, return how much data read*/
    __kernel_ssize_t (*aio_write) (struct kiocb*, const char* __user, __kernel_size_t, __kernel_loff_t);
    int (*readdir) (struct file*, void* /*param*/); // check header for filldir_t
    unsigned (*poll) (struct filr*, struct poll_table_struct*);     /*oquery if read or write would block, if NULL it doesnt block*/
    int (*ioctl) (struct inode*, struct file*, unsigned int, unsigned long);
    long (*unlocked_ioctl) (struct file*, unsigned int, unsigned long);
    long (*compat_ioctl) (struct file*, unsigned int, unsigned long);
    int (*nmap) (struct file*, struct vm_area_struct*);
    int (*open) (struct inode*, struct file*);
    int (*flush) (struct file*);
    int (*release) (struct inode*, struct file*);
    int (*fsync) (struct file*, struct dentry*, int datasync);
    int(*aio_fsync) (struct kiocb*, int datasync);
    int (*fasync) (int, struct file*, int);
    int(*lock) (struct file*, int, struct file_lock*);
    __kernel_ssize_t (*readv) (struct file*,const struct iovec*, unsigned long, __kernel_loff_t);
    __kernel_ssize_t (*writev) (struct file*,const struct iovec*, unsigned long, __kernel_loff_t);
    __kernel_ssize_t (*sendfile) (struct file*, __kernel_loff_t, __kernel_ssize_t, /*,*/ void*); // read_actor_t
    __kernel_ssize_t (*sendpage) (struct file*, struct page*, int, __kernel_ssize_t, __kernel_loff_t*, int);
    unsigned long (*get_unmapped_area) (struct file*, unsigned long, unsigned);
    int (*check_flags) (int);
    int (*dir_notify) (struct file* flip, unsigned long);
    int (*flock) (struct file*, int, struct file_lock*);
};

/**
 * register a device
 * return 0 upon successful registration
*/
register_chrdev(unsigned int val,const char* word, struct file_operations* fops){return 0;}

/**
 * unregister device
 * remove char_dev
*/
unregister_chrdrv(unsigned int majorNo, const char* charDev){return 0;}


/**
 * arguments as (cdev struct, sirst device number to which device responds, how many devices are associated)
 * int cdev_add(struct cdev* cdev, dev_t num, unsigned int count); 
*/