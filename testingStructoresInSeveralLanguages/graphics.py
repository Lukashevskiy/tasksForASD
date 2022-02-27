import matplotlib.pyplot as plt

def get_data(path):
	x = []
	y = []
	t = []
	with open(path, 'r') as f:
		for item in f:
			x_i, y_i, t_i = map(int,item.split())
			x.append(x_i)
			y.append(y_i)
			t.append(t_i)		
	return x, y, t


path_cpp_test = "./outCpp.txt"
path_py_test = "./outPy.txt"

cpp_test = get_data(path_cpp_test)
py_test = get_data(path_py_test)

print(cpp_test)
print(py_test)
plt.subplot(121)
plt.title("сравнение потребления памяти")
plt.xlabel("колличество елементов в map")
plt.ylabel("занимаемое место в памяти")
plt.plot(cpp_test[0], cpp_test[1])
plt.plot(py_test[0], py_test[1])

plt.subplot(122)
plt.title("сравнение времени")
plt.xlabel("колличество элементов в map")
plt.ylabel("величина времени добавление всех елементов с контейнер")
plt.plot(cpp_test[0], cpp_test[2])
plt.plot(py_test[0], py_test[2])

plt.show()
