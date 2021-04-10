import pylab
import numpy as np
pylab.rcParams["lines.linewidth"] = 2
x = np.linspace(0.01,50)
pylab.plot(x, x**2, label='n^2')
pylab.plot(x, .125 * x**3, label='.125 * n^3')
pylab.plot(x, x**3, label='n^3')
pylab.plot(x, x, label='n')
pylab.plot(x, pylab.log2(x), label='log2(n)')
pylab.plot(x, x * pylab.log2(x), label='nlog(n)')
pylab.ylim(0,100000)
pylab.legend()
pylab.show()

x = np.linspace(5,20)
pylab.plot(x, 2**x, label='2^n')
pylab.plot(x, x**3, label='n^3')
pylab.legend()
pylab.show()

x = np.linspace(5,20)
pylab.plot(x, 2**x, label='2^n')
pylab.plot(x, 3**x, label='3^n')
pylab.legend()
pylab.show()
