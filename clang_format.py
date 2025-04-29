import defines
from glob import iglob
import os.path
from subprocess import run


def main():
    index = 1
    changed = {}

    def format(file):
        nonlocal index
        cmd = ['clang-format', '-style=file', '-i', file]
        print(index, ' '.join(cmd))
        index += 1
        last = os.path.getmtime(file)
        run(cmd)
        now = os.path.getmtime(file)
        if now > last:
            changed[file] = now - last

    general = defines.get_general_config()
    sourceFolder = os.path.join(defines.TOP_DIR, general['SRCDIR'])
    for header in iglob(os.path.join(sourceFolder, '**',
                                     '*' + general['HEADEREXT']),
                        recursive=True):
        format(header)
    for source in iglob(os.path.join(sourceFolder, '**',
                                     '*' + general['SRCEXT']),
                        recursive=True):
        format(source)
    for x in changed:
        print(x, changed[x])


if __name__ == '__main__':
    main()
