#include <linux/netdevice.h>
 
int register_netdevice(struct net_device*);
int unregister_netdevice(struct net_device*);

struct net_device{ /*implement this!*/
    ;
};

int register_netdevice(struct net_device* dev){return 0;}
int unregister_netdevice(struct net_device* dev){return 0;}
