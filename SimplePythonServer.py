#!/usr/bin/env python

from http.server import BaseHTTPRequestHandler,HTTPServer
from urllib.parse import parse_qs
from sys import argv
import sys 
import json
import os

class PostHandler(BaseHTTPRequestHandler):
    def _set_headers(self):
        self.send_response(200)
        self.send_header('Content-type', 'application/json')
        self.end_headers()
        
    def do_POST(self):
        content_length = int(self.headers['Content-Length']) 
        post_data = self.rfile.read(content_length) 
        print("post_data: " + str(post_data))
        self._set_headers()
        dataDictionary = parse_qs(post_data.decode('utf-8'))
        dirFunctionDataFiles = "cgi-bin/functionsAnswers"
        if ('function_name' in dataDictionary):
            function_name = dataDictionary.get('function_name')
            path = os.path.join(os.getcwd(), dirFunctionDataFiles, function_name[0])
            fileHandler = open(path, 'r')
            fromFile = fileHandler.read()
            print(fromFile) 
            self.wfile.write(fromFile.encode())
        else:
            print("No function name")
 
def run(server_class=HTTPServer, handler_class=PostHandler, port=8000):
    server_address = ('', port)
    httpd = server_class(server_address, handler_class)
    print('Server started on ' + str(port))
    httpd.serve_forever()

if __name__ == "__main__":
    try:
        if len(argv) == 2:
            run(port=int(argv[1]))
        else:
            run()
    except KeyboardInterrupt:
        print("")
        print("Ctrl C - Stopping server")
        sys.exit(1)
