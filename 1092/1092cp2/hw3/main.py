string = "#include <stdio.h>\nint main(){\n    int array[1000000] = {0,"
f = open("test.c", "w")
f.write(string)
solutions = []
solutions.append(0)
for ea in range(1,1000010):
   solutions.append(1000010)
perfect = 1
num = 1
while(perfect <= 1000000):
    for k in range(perfect, 1000001):
        solutions[k] = min(solutions[k], solutions[k - perfect] + 1)
        #print(solutions[k])
    num += 1
    perfect = num*num
    print(perfect)
for i in range(1,1000001):
    if i != 1:
        f.write(",")
    f.write(str(solutions[i]))
f.write("};\n    int N;\n    scanf(\"%d\",&N);\n    printf(\"%d\\n\", array[N]);\n}")
f.close
