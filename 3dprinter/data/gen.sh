g++ -O2 -static ../submissions/accepted/3dprinter_unnar.cpp -o sol

python3 gen_random.py 423 > secret/01-random.in
python3 gen_random.py 346 > secret/02-random.in
python3 gen_random.py 754 > secret/03-random.in
python3 gen_random.py 123 > secret/04-random.in
python3 gen_random.py 675 > secret/05-random.in
python3 gen_random.py 663 > secret/06-random.in
python3 gen_random.py 411 > secret/07-random.in
python3 gen_random.py 129 > secret/08-random.in
python3 gen_random.py 873 > secret/09-random.in
python3 gen_random.py 518 > secret/10-random.in
python3 gen_random_worst.py 101 > secret/11-random-twos.in
python3 gen_random_worst.py 489 > secret/12-random-twos.in
python3 gen_random_worst.py 791 > secret/13-random-twos.in
python3 gen_random_worst.py 337 > secret/14-random-twos.in
python3 gen_random_worst.py 811 > secret/15-random-twos.in
python3 gen_random_worst.py 319 > secret/16-random-twos.in
python3 gen_random_worst.py 409 > secret/17-random-twos.in
python3 gen_random_worst.py 985 > secret/18-random-twos.in
python3 gen_random_worst.py 666 > secret/19-random-twos.in
python3 gen_random_worst.py 765 > secret/20-random-twos.in
echo 10000 > secret/21-max.in
echo 9999 > secret/22-nearmax.in
echo 4 > secret/23-small.in
echo 8191 > secret/24-lasttwo.in
echo 8192 > secret/25-lasttwo.in
echo 8193 > secret/26-lasttwo.in


for x in secret/*.in
do
	./sol < $x > ${x/%.in/.ans}
done
