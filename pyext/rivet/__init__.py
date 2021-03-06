import sys
try:
    import ctypes
    sys.setdlopenflags(sys.getdlopenflags() | ctypes.RTLD_GLOBAL)
    del ctypes
except:
    import dl
    sys.setdlopenflags(sys.getdlopenflags() | dl.RTLD_GLOBAL)
    del dl
del sys

from rivet.core import *
__version__ = core.version()

from rivet.plotinfo import *
from rivet.aopaths import *
import spiresbib, util
