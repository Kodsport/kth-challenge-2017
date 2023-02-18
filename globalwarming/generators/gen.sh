#!/usr/bin/env bash

g++ -Wall -O2 worst_case_size.cpp -o worst_case_size

echo 200 250 | ./worst_case_size | python gen_random_specific.py 1 > ../data/secret/01.in
echo 200 250 | ./worst_case_size | python gen_random_specific.py 2 > ../data/secret/02.in
echo 200 250 | ./worst_case_size | python gen_random_specific.py 3 > ../data/secret/03.in
echo 200 250 | ./worst_case_size | python gen_random_specific.py 4 > ../data/secret/04.in
echo 200 250 | ./worst_case_size | python gen_random_specific.py 5 > ../data/secret/05.in
echo 200 250 | ./worst_case_size | python gen_random_specific.py 6 > ../data/secret/06.in
echo 200 250 | ./worst_case_size | python gen_random_specific.py 7 > ../data/secret/07.in
echo 200 250 | ./worst_case_size | python gen_random_specific.py 8 > ../data/secret/08.in

echo 22 | python gen_random_specific.py 9 > ../data/secret/09.in
echo 21 | python gen_random_specific.py 10 > ../data/secret/10.in
echo 21 1 | python gen_random_specific.py 11 > ../data/secret/11.in
echo 21 1 | python gen_random_specific.py 12 ordered > ../data/secret/12.in
echo 3 3 | python gen_random_specific.py 13 > ../data/secret/13.in
echo 15 15 | python gen_random_specific.py 14 > ../data/secret/14.in
echo 22 5 3 | python gen_random_specific.py 15 ordered > ../data/secret/15.in
echo 22 6 1 1 | python gen_random_specific.py 16 ordered > ../data/secret/16.in

yes 1 | head -200 | python gen_random_specific.py 17 > ../data/secret/17.in
yes 2 | head -100 | python gen_random_specific.py 18 > ../data/secret/18.in
yes 3 | head -66 | python gen_random_specific.py 19 > ../data/secret/19.in
yes 4 | head -41 | python gen_random_specific.py 20 > ../data/secret/20.in
yes 5 | head -24 | python gen_random_specific.py 21 > ../data/secret/21.in
yes 6 | head -16 | python gen_random_specific.py 22 > ../data/secret/22.in
yes 7 | head -11 | python gen_random_specific.py 23 > ../data/secret/23.in
yes 8 | head -8 | python gen_random_specific.py 24 > ../data/secret/24.in
yes 9 | head -6 | python gen_random_specific.py 25 > ../data/secret/25.in
yes 10 | head -5 | python gen_random_specific.py 26 > ../data/secret/26.in
yes 11 | head -4 | python gen_random_specific.py 27 > ../data/secret/27.in
yes 12 | head -3 | python gen_random_specific.py 28 > ../data/secret/28.in
yes 16 | head -2 | python gen_random_specific.py 29 > ../data/secret/29.in

echo 200 250 | ./worst_case_size | python gen_random_specific.py 31 binary > ../data/secret/31.in
echo 200 250 | ./worst_case_size | python gen_random_specific.py 32 binary > ../data/secret/32.in
echo 200 250 | ./worst_case_size | python gen_random_specific.py 33 binary > ../data/secret/33.in

echo 200 250 | ./worst_case_size | python gen_random_specific.py 34 small > ../data/secret/34.in
echo 200 250 | ./worst_case_size | python gen_random_specific.py 35 small > ../data/secret/35.in
echo 200 250 | ./worst_case_size | python gen_random_specific.py 36 small > ../data/secret/36.in

echo 200 250 | ./worst_case_size | python gen_random_specific.py 37 unique > ../data/secret/37.in
echo 200 250 | ./worst_case_size | python gen_random_specific.py 38 unique > ../data/secret/38.in
echo 200 250 | ./worst_case_size | python gen_random_specific.py 39 unique > ../data/secret/39.in

echo 200 250 | ./worst_case_size | python gen_random_specific.py 40 unique binary > ../data/secret/40.in
echo 200 250 | ./worst_case_size | python gen_random_specific.py 41 unique binary > ../data/secret/41.in
echo 200 250 | ./worst_case_size | python gen_random_specific.py 42 unique binary > ../data/secret/42.in

echo 200 250 | ./worst_case_size | python gen_random_specific.py 43 unique small > ../data/secret/43.in
echo 200 250 | ./worst_case_size | python gen_random_specific.py 44 unique small > ../data/secret/44.in
echo 200 250 | ./worst_case_size | python gen_random_specific.py 45 unique small > ../data/secret/45.in

echo 200 250 | ./worst_case_size | python gen_random_specific.py 46 close > ../data/secret/46.in
echo 200 250 | ./worst_case_size | python gen_random_specific.py 47 close > ../data/secret/47.in
echo 200 250 | ./worst_case_size | python gen_random_specific.py 48 close > ../data/secret/48.in

echo 200 250 | ./worst_case_size | python gen_random_specific.py 50 close > ../data/secret/49.in
echo 200 250 | ./worst_case_size | python gen_random_specific.py 51 close > ../data/secret/50.in
echo 200 250 | ./worst_case_size | python gen_random_specific.py 52 close > ../data/secret/51.in
echo 200 250 | ./worst_case_size | python gen_random_specific.py 53 close > ../data/secret/52.in
echo 200 250 | ./worst_case_size | python gen_random_specific.py 65 close > ../data/secret/53.in
echo 200 250 | ./worst_case_size | python gen_random_specific.py 66 close > ../data/secret/54.in
echo 200 250 | ./worst_case_size | python gen_random_specific.py 67 close > ../data/secret/55.in
echo 200 250 | ./worst_case_size | python gen_random_specific.py 70 close > ../data/secret/56.in

