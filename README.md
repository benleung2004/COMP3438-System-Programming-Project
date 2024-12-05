One light google doc:
https://docs.google.com/document/d/1DmSQLc1xEarfVLW_li8w27bqHSNejWF2PFlqMBw0Ndk/edit?tab=t.eqvt30h23csr

Block device Demo google doc:
https://docs.google.com/document/d/1DmSQLc1xEarfVLW_li8w27bqHSNejWF2PFlqMBw0Ndk/edit?tab=t.ajb27bhz2rfj

Project:
Y drive/subject/vm_image/EmbeddedSystem/EmbeddedSystem_2024A
Go to Firefox, polyu bb, Week 9 Helloworld demo, download
put all files to desktop
terminal

sudo bash (password:12345)
cd arm-board/
cd linux-3.0.8/
cd drivers/
# cd char/
# cp /home/comp3438/Desktop/helloworld_driver.c helloworld_driver.c 
# cp /home/comp3438/Desktop/Kconfig Kconfig
# cp /home/comp3438/Desktop/Makefile Makefile

# cd .. cd .. cd ..(~/arm-board)
# cp /home/comp3438/Desktop/helloworld_user.c helloworld_user.c
cd linux3.0.8
make menuconfig
Device Driver
Character Driver
Helloworld(M)
make
cd .. (/arm-board)
### arm-linux-gcc -o helloworld_user helloworld_user.c

Open Putty
COM3, 115200
cd /mnt
cd nfs
### mount -t nfs 192.168.1.1:/home/comp3438/arm-board /mnt/nfs -o nolock
cd .. 
cd nfs
ls(should be 3 files)
cd linux-3.0.8/
cd drivers/
cd char
### insmod helloworld_driver.ko
cd /proc
### mknod /dev/helloworld c 250 1
cd ..
cd ..
cd /mnt
cd nfs
./helloworld_user
rm /dev/helloworld
rmmod helloworld_driver

Final output:
Device helloworld char driver opened.
Device helloworld char driver closed.
Got the message from /dev/helloworld: "Hello World!!!".
