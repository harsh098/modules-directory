/*
* This module raises a Custom panic and panics the kernel with a dmesg log
*
*/

#include<linux/kernel.h>
#include<linux/panic.h>
#include<linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Harsh Mishra");
MODULE_DESCRIPTION("Generate Panic for LFX Kernel Bug Fixing Spring 2023");


static int __init initiate_panic(void){
        
        printk(KERN_INFO KBUILD_MODNAME "Initiating Panic Module...\n");
        panic("Custom Generated Kernel Panic Message as a Proof");
//      printk(KERN_INFO KBUILD_MODNAME "Panic Task Successful \n");    
        return 0;
}



static void __exit start_cleanup(void){

        printk(KERN_INFO KBUILD_MODNAME "Panic State Achieved. Starting Cleanup Tasks...\n");
        
}

module_init(initiate_panic);
module_exit(start_cleanup);
