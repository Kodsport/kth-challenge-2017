g++ -O2 -static ../submissions/accepted/evenodd_js.cpp -o sol

python3 gen_random.py 423 > secret/01-random.in
python3 gen_random.py 346 > secret/02-random.in
python3 gen_random.py 754 > secret/03-random.in
python3 gen_random.py 123 > secret/04-random.in
python3 gen_random.py 675 > secret/05-random.in
python3 gen_random.py 663 > secret/06-random.in
python3 gen_random.py 411 > secret/07-random.in
# 8, 9, 10 by hand
python3 gen_random_twopows.py 411 > secret/11-random-twopow.in
python3 gen_random_twopows.py 543 > secret/12-random-twopow.in
python3 gen_random_twopows.py 754 > secret/13-random-twopow.in
python3 gen_random_twopows.py 126 > secret/14-random-twopow.in
python3 gen_random_twopows.py 992 > secret/15-random-twopow.in

for x in secret/*.in
do
	./sol < $x > ${x/%.in/.ans}
done
