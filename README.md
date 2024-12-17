One light google doc:
https://docs.google.com/document/d/1DmSQLc1xEarfVLW_li8w27bqHSNejWF2PFlqMBw0Ndk/edit?tab=t.eqvt30h23csr

Block device Demo google doc:
https://docs.google.com/document/d/1DmSQLc1xEarfVLW_li8w27bqHSNejWF2PFlqMBw0Ndk/edit?tab=t.ajb27bhz2rfj

Project:
Y drive/subject/vm_image/EmbeddedSystem/EmbeddedSystem_2024A
Go to Firefox, polyu bb, Week 9 Helloworld demo, download
terminal

sudo bash (password:12345)
cd arm-board/
# cp /home/comp3438/Desktop/helloworld_user.c helloworld_user.c
# arm-linux-gcc -o helloworld_user helloworld_user.c
cd linux-3.0.8/
cd drivers/
# cd char/
# cp /home/comp3438/Download/helloworld/helloworld_driver.c helloworld_driver.c 
# cp /home/comp3438/Download/helloworld/Kconfig Kconfig
# cp /home/comp3438/Download/helloworld/Makefile Makefile
# cd .. cd ..(~/arm-board/Linux3.0.8)
make menuconfig
Device Driver
Character Driver
Helloworld(M)
make
-----------------------------------------------------------------------
# Setup:
Open Putty
COM3, 115200
cd /mnt
cd nfs
# mount -t nfs 192.168.1.1:/home/comp3438/arm-board /mnt/nfs -o nolock
-----------------------------------------------------------------------
cd .. 
cd nfs
ls(should be 3 files)
cd linux-3.0.8/
cd drivers/
cd char #Navigates to the char directory where the compiled driver module (helloworld_driver.ko) is located.
### insmod helloworld_driver.ko Inserts (loads) the helloworld_driver kernel module into the kernel.
cd /proc ### Enters the /proc directory, which contains runtime kernel information.
### mknod /dev/helloworld c 250 1 #Creates a device file /dev/helloworld with character device, major number 250, minor number 1
cd ..
cd ..
cd /mnt
cd nfs
./helloworld_user #Executes the user-space program, which interacts with the device driver and outputs messages.
rm /dev/helloworld Removes the device file created earlier.
rmmod helloworld_driver Removes (unloads) the helloworld_driver module from the kernel.

Final output:
Device helloworld char driver opened.
Device helloworld char driver closed.
Got the message from /dev/helloworld: "Hello World!!!".
