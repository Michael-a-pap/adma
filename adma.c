#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/io.h>
#include <linux/interrupt.h>

#include <linux/of_address.h>
#include <linux/of_device.h>
#include <linux/of_platform.h>


static int __init init_adma(void)
{
	pr_info("Hello world\n");
	return 0;
}

static void __exit exit_adma(void)
{
	pr_info("Goodbye cruel world!\n");
}
module_init(init_adma);
module_exit(exit_adma);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Michael A. Papachatzakis");
MODULE_DESCRIPTION("Kernel module for the accelerator DMA");
