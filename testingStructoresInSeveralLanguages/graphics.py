import matplotlib.pyplot as plt

def get_data(path):
    x = []
    y = []
    with open(path, 'r') as f:
          for item in f:
              x_i, y_i = map(int,item.split())
              x.append(x_i)
              y.append(y_i)
    return x, y



path_cpp_test = "./outCpp.txt"
path_py_test = "./outPy.txt"

cpp_test = get_data(path_cpp_test)
py_test = get_data(path_py_test)

print(cpp_test)
#plt.plot(cpp_test[0], cpp_test[1])
plt.plot(py_test[0], py_test[1])
plt.show()
