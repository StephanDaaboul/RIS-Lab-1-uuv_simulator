## *********************************************************
##
## File autogenerated for the uuv_control package
## by the dynamic_reconfigure package.
## Please do not edit.
##
## ********************************************************/

from dynamic_reconfigure.encoding import extract_params

inf = float('inf')

config_description = {'name': 'Default', 'type': '', 'state': True, 'cstate': 'true', 'id': 0, 'parent': 0, 'parameters': [{'name': 'pos_p', 'type': 'double', 'default': 1.0, 'level': 0, 'description': 'p component of pid for position', 'min': 0.0, 'max': 100.0, 'srcline': 291, 'srcfile': '/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'pos_i', 'type': 'double', 'default': 0.0, 'level': 0, 'description': 'i component of pid for position.', 'min': 0.0, 'max': 100.0, 'srcline': 291, 'srcfile': '/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'pos_d', 'type': 'double', 'default': 0.0, 'level': 0, 'description': 'd component of pid for position.', 'min': 0.0, 'max': 100.0, 'srcline': 291, 'srcfile': '/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'pos_sat', 'type': 'double', 'default': 10.0, 'level': 0, 'description': 'saturation of pid for position.', 'min': 0.0, 'max': 100.0, 'srcline': 291, 'srcfile': '/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'rot_p', 'type': 'double', 'default': 1.0, 'level': 0, 'description': 'p component of pid for orientation.', 'min': 0.0, 'max': 100.0, 'srcline': 291, 'srcfile': '/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'rot_i', 'type': 'double', 'default': 0.0, 'level': 0, 'description': 'i component of pid for orientation.', 'min': 0.0, 'max': 100.0, 'srcline': 291, 'srcfile': '/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'rot_d', 'type': 'double', 'default': 0.0, 'level': 0, 'description': 'd component of pid for orientation.', 'min': 0.0, 'max': 100.0, 'srcline': 291, 'srcfile': '/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}, {'name': 'rot_sat', 'type': 'double', 'default': 3.0, 'level': 0, 'description': 'saturation of pid for orientation.', 'min': 0.0, 'max': 100.0, 'srcline': 291, 'srcfile': '/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py', 'edit_method': '', 'ctype': 'double', 'cconsttype': 'const double'}], 'groups': [], 'srcline': 246, 'srcfile': '/home/stephan/catkinws/src/dynamic_reconfigure/src/dynamic_reconfigure/parameter_generator_catkin.py', 'class': 'DEFAULT', 'parentclass': '', 'parentname': 'Default', 'field': 'default', 'upper': 'DEFAULT', 'lower': 'groups'}

min = {}
max = {}
defaults = {}
level = {}
type = {}
all_level = 0

#def extract_params(config):
#    params = []
#    params.extend(config['parameters'])
#    for group in config['groups']:
#        params.extend(extract_params(group))
#    return params

for param in extract_params(config_description):
    min[param['name']] = param['min']
    max[param['name']] = param['max']
    defaults[param['name']] = param['default']
    level[param['name']] = param['level']
    type[param['name']] = param['type']
    all_level = all_level | param['level']

