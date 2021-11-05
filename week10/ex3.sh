touch _ex3.txt
echo 'Slava Koshman' >> _ex3.txt
chmod ugo-x _ex3.txt
ls -l _ex3.txt
chmod g-rwx _ex3.txt
chmod uo=rwx _ex3.txt
ls -l _ex3.txt
chmod g=u _ex3.txt
ls -l _ex3.txt