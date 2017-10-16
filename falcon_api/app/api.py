
from werkzeug.routing import BaseConverter

from flask import Flask, request, url_for

from flask_restful import (Resource, Api,	
							fields, marshal_with,
							reqparse, 
							)
from flask_pymongo import PyMongo # Pymongo is a wrapper around MongoDB to be used with flask.


import jwt

# errors = {
#     'UserAlreadyExistsError': {
#         'message': "A user with that username already exists.",
#         'status': 409,
#     },
#     'ResourceDoesNotExist': {
#         'message': "A resource with that ID no longer exists.",
#         'status': 410,
#         'extra': "Any extra information you want.",
#     },
# }

app = Flask(__name__)
mongo = PyMongo(app)
api = Api(app) # use errors attribute of the API constructor to return error
			   # messages pertaining to certain errors

parser = reqparse.RequestParser(bundle_errors=True)



class UrlField(fields.Raw):
	def format(self, value):
		return "localhost:8000/{}".format(value)


# res_fields = {
# 	'name' : fields.String,
# 	'url' : UrlField(attribute=),
# }

entities = [{
			'name': "Things", 
			'url': "localhost:8000/Things"
			},
			{
			'name': 'Locations', 
			'url': "localhost:8000/Locations"
			},
			{
			'name': 'Observations', 
			'url': "localhost:8000/Observations"
			},
]

things = [{
	'@iot_id' : 0,
	'name': 'Humidity Sensor',
	'description': 'Measures humidity'
	}, 
	{
	'@iot_id' : 1,
	'name': 'Wind Speed Sensor',
	'description': 'Measures the wind speed'
	},
	{
	'@iot_id' : 2,
	'name': 'Pyranometer',
	'description': 'Measures solar irradiance on a planar surface'
	},
]
		
class Entity(Resource):
	def get(self, **kwargs):
		return {'values': entities}


class Things(Resource):	
	def get(self):		
		return {'things': things}
	
	def post(self):
		parser.add_argument('@iot_id', type=int, required=True)
		parser.add_argument('name', type=str, required=True)
		parser.add_argument('description', type=str, required=True)
		args = parser.parse_args()
		things.append({'@iot_id': args['@iot_id'], 'name':args['name'], 'description': args['description']})
		return {'value': things}

	def put(self):
		pass

class Login(Resource):
	def get(self, **kwargs):
		auth = request.authorization


class Unprotected(Resource):
	def get(self, **kwargs):
		pass


class Protected(Resource):
	def get(self, **Kwargs):
		return {'message': 'Only users with valid token can access this.'}
api.add_resource(Entity,'/', "/Entities", endpoint='entity_ep')
api.add_resource(Things,'/Things', endpoint='things_ep')


if __name__ == "__main__":
	app.run(debug=True, port=8000)


