import os

def compile(file_name):
	compile_command = 'gcc ' + file_name + ' -o exec -lm -O3 -Wall'
	os.system(compile_command)

def execute_program(qnt_cases):
	for i in range(qnt_cases):
		command = './exec < input/' + str(i + 1) + '.inp > useroutput/' + str(i + 1) + '.out'
		os.system(command)

def read_file(file_path):
	try:
		file = open(file_path, 'r')
		msg = file.read()
		file.close()
		return msg
	except FileNotFoundError:
		print(text_error)
		return ''

def judge(qnt_cases, points_question):
	hits = 0
	for i in range(qnt_cases):
		f1 = read_file('output/' + str(i + 1) + '.out')
		f2 = read_file('useroutput/' + str(i + 1) + '.out')
		print('julgando o caso: ' + str(i + 1))
		print('julgamento: ', end='')
		if(f1 == f2): 
			hits += 1
			print('correto')
		else:	
			print('incorreto')
	print('----------------------------------------------------')
	print('foram acertados ' + str(hits) + ' casos de teste de um total de ' + str(qnt_cases))
	print(points_question * float(qnt_cases/hits))

def run(file_name, qnt_cases):
	compile(file_name)
	execute_program(qnt_cases)
	judge(qnt_cases, 5.0)

run(input(), int(input()))