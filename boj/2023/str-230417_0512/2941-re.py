'''
import re
s = re.sub(pattern, repl, s)
'''

import re
print(len(re.sub("c=|c-|dz=|d-|lj|nj|s=|z=", "0", input())))