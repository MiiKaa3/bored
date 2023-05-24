print(f'{__import__("sys").argv[1].split("/")[2].split(".")[0]}_old={__import__("hashlib").sha256(str(open(__import__("sys").argv[1], "r").read()).encode("utf-8")).hexdigest()}')
