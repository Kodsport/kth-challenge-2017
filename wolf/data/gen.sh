g++ -O2 -static ../submissions/accepted/war_js.cpp -o sol

python3 gen_all.py suits=H > secret/01-all_H.in
python3 gen_all.py suits=S > secret/02-all_S.in
python3 gen_all.py suits=C > secret/03-all_C.in
python3 gen_all.py suits=D > secret/04-all_D.in
python3 gen_all.py suits=HS > secret/05-all_HS.in
python3 gen_all.py suits=CD > secret/06-all_CD.in
python3 gen_all.py suits=HSC > secret/07-all_HSC.in
python3 gen_all.py suits=DCH > secret/08-all_DCH.in
python3 gen_all.py suits=HSCD > secret/09-all_HSCD.in
python3 gen_rand.py n=26 3456 > secret/10-random26.in
python3 gen_rand.py n=26 635 > secret/11-random26.in
python3 gen_rand.py n=26 1643 > secret/12-random26.in
python3 gen_rand.py n=26 6546 > secret/13-random26.in
python3 gen_rand_which.py n=26 which=lower 236 > secret/14-random26-lower.in
python3 gen_rand_which.py n=26 which=lower 7543 > secret/15-random26-lower.in
python3 gen_rand_which.py n=26 which=higher 1364 > secret/16-random26-lower.in
python3 gen_rand_which.py n=26 which=higher  1235 > secret/17-random26-lower.in
python3 gen_rand_which.py n=25 which=lower  7543 > secret/18-random26-lower.in
python3 gen_rand_which.py n=25 which=lower 234621 > secret/19-random26-lower.in
python3 gen_rand_which.py n=25 which=higher 6524 > secret/20-random26-lower.in
python3 gen_rand_which.py n=25 which=higher 34567 > secret/21-random26-higher.in
python3 gen_rand_which.py n=27 which=lower 5678 > secret/22-random27-lower.in
python3 gen_rand_which.py n=27 which=lower 234 > secret/23-random27-lower.in
python3 gen_rand_which.py n=27 which=higher 1752 > secret/24-random27-higher.in
python3 gen_rand_which.py n=27 which=higher 5416  > secret/25-random27-higher.in
python3 gen_rand.py n=27 5473 > secret/26-random27.in
python3 gen_rand.py n=28 6357 > secret/27-random28.in
python3 gen_rand.py n=29 15643 > secret/28-random29.in
python3 gen_rand.py n=30 62546 > secret/29-random30.in


for x in secret/*.in
do
	./sol < $x > ${x/%.in/.ans}
done
