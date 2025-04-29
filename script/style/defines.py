import os.path

DIR = os.path.dirname(os.path.abspath(__file__))
SCRIPT_DIR = os.path.dirname(DIR)
TOP_DIR = os.path.dirname(SCRIPT_DIR)


def get_general_config():
    with open(os.path.join(SCRIPT_DIR, 'make.json')) as f:
        from json import load
        return load(f)['GENERAL']
