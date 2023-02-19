/*
* The Following Module takes 2 arguments and logs the message to output accordingly
* passes int , No of passes to run the message loop for
* printk_loops int No of loops in each pass
* The module prints "Hello World" exactly printk_loops*passes times 
*/

#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Harsh Mishra");
MODULE_DESCRIPTION("Hello World Module for the Linux Kernel");

static int printk_loops = 0;
module_param(printk_loops, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
static int passes = 0;
module_param(passes, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(passes, "No of passes to loop for");
MODULE_PARM_DESC(printk_loops, "No of loops in each pass");


static int __init hello_init(void)
{

        int counter = 0;
        int pass = 0;

        for(pass=0; pass<passes; pass++){
                printk(KERN_INFO "PASS NO %x\n", pass+1);
                for(counter=0; counter<printk_loops; counter++){
                                printk(KERN_INFO "Hello World!\n");
                }
        }
        return 0;
}

static void __exit hello_cleanup(void)
{
        printk(KERN_INFO "Cleanup Module.\n");

}

module_init(hello_init);
module_exit(hello_cleanup);
