/*
    Realtek Semiconductor Corp Sim card reader
    @author : hamza naper
    @site : www.naper.eu

*/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>
 
#define SC_VENDOR_ID        0x0bda      /* Realtek Semiconductor Corp. */
#define SC_PRODUCT_ID       0x0161      /* Mass Storage Device */
#define SC_MINOR_BASE       0

#define SIM_INTERFACE_CLASS 11          /* Chip/SmartCard */

#define B_LENGHT            7

/* bEndpointAddress     0x83  EP 3 IN */

static struct usb_class_driver sc_class = {
    .name = "sc%d",
    .minor_base = SC_MINOR_BASE,
};

static int sc_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
    printk(KERN_INFO "SC drive (%04X:%04X) plugged\n", id->idVendor, id->idProduct);
    return 0;
}
 
static void sc_disconnect(struct usb_interface *interface)
{
    printk(KERN_INFO "SC drive removed\n");
}
 
static struct usb_device_id sc_table[] =
{
    { USB_DEVICE(SC_VENDOR_ID, SC_PRODUCT_ID) },
    {} /* Terminating entry */
};
MODULE_DEVICE_TABLE (usb, pen_table);
 
static struct usb_driver pen_driver =
{
    .name = "sim card reader",
    .id_table = sc_table,
    .probe = sc_probe,
    .disconnect = sc_disconnect,
};
 
static int __init sc_init(void)
{
    return usb_register(&pen_driver);
}
 
static void __exit sc_exit(void)
{
    usb_deregister(&pen_driver);
}
 
module_init(sc_init);
module_exit(sc_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Hamza Naper");
MODULE_DESCRIPTION("Power Star SIM card reader USB");