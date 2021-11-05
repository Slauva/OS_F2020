touch lofs.img
sudo dd if=/dev/zero of=lofs.img bs=1M count=60
sudo losetup -fP lofs.img
mkfs.ext4 lofs.img
mkdir lofsdisk
sudo mount -o loop /dev/loop0 lofsdisk/
sudo chmod 777 lofsdisk