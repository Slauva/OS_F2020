sudo cp -a /bin lofsdisk
sudo cp -a /usr lofsdisk
sudo cp -a /lib lofsdisk
sudo cp -a /lib64 lofsdisk

gcc ex2.c -o ex2
sudo cp -a ex2 lofsdisk

sudo chroot lofsdisk ./ex2 >> ex2.txt
./ex2 >> ex2.txt