gcc ex2.c -o ex2
./ex2 &
n=5
for i in `seq $n` 
do
  pstree
  sleep 5
done