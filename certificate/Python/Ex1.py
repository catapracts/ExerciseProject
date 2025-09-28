dec = 13
bin = ''

while(dec > 0):
    rmd = dec % 2
    dec = dec // 2
    bin = str(rmd) + bin

print(bin)