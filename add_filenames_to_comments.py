import os
from glob import glob
result = [y for x in os.walk(".") for y in glob(os.path.join(x[0], '*.cpp'))]
result += [y for x in os.walk(".") for y in glob(os.path.join(x[0], '*.h'))]

print(result)

for name in result:
  base = os.path.basename(name)
  print(base)
  with open(name, 'r') as file :
    filedata = file.read()

  filedata = filedata.replace('{{file}}', base)

  with open(name, 'w') as file:
    file.write(filedata)
