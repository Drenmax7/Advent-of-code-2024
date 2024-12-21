
file = open("template.hpp","r")
hpp = file.read()
file.close()

file = open("template.cpp","r")
cpp = file.read()
file.close()

for i in range(26,26):
    fichier = open(f"j{i}.hpp","w")
    fichier.write(hpp.replace("{}",str(i)))
    fichier.close()

    fichier = open(f"j{i}.cpp","w")
    fichier.write(cpp.replace("{}",str(i)))
    fichier.close()

    #fichier = open(f"instance/j{i}.txt","w").close()
