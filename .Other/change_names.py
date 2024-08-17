import os


"""
:rtype: None

Change the name of each file in the current directory
"""
def rename_files():
    dir=os.getcwd()
    files_list=os.listdir(dir)

    for filename in files_list:
        if os.path.isfile(os.path.join(dir, filename)):
            new_name = f"AR_{filename}.cpp"

            os.rename(os.path.join(dir, filename), os.path.join(dir, new_name))


def main():
    rename_files()

main()
