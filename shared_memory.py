import mmap

position = [-10.0, 0.0, 0.0]

with open("position.txt", "w") as f:
    f.write(str(' '*1000))

with open("position.txt", "r+b") as f:
    mm = mmap.mmap(f.fileno(), 0)
    #print(mm.readline())  # prints b"Hello Python!\n"
    data = "ball, "+format(position[0],'.3f')+", "+format(position[1],'.3f')+", "+format(position[2],'.3f')+"\r\n"
    data += "red1, "+format(position[0],'.3f')+", "+format(position[1],'.3f')+", "+format(position[2],'.3f')+"\r\n"
    mm[0:len(data)] = data.encode()
    mm.seek(0)
    print(mm.readline())  # prints b"Hello  world!\n"
    print(mm.readline())  # prints b"Hello  world!\n"
    mm.close()
