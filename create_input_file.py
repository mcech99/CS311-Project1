import random

def main():
	alpha = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']

	f = open("infile.txt","w")

	for i in range(6000):
		line = ""
		while(len(line) < 80):
			if len(line) > 70:
				word_len = 80 - (len(line))
				space = False
			else:
				word_len = random.randint(1,11)
				space = True
			new_word = ""
			for j in range(word_len):
				new_word += alpha[random.randint(0,len(alpha)-1)]
			if space == True:
				new_word += " "
			line += new_word
		f.write(line+'\n')


	f.close()

main()
