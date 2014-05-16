#include <string>

class NginxConfig;

// Interface for response handlers.
// * All of your handlers (echo, static file, etc.) should inherit from this
//   class.
// * Response handler objects should be long-lived -- they should be created
//   once, at server startup.
class ResponseHandlerInterface {
 public:
  // Initializes the response handler object. The config argument is just the
  // portion that applies to the response handler.
  // Returns true if successful.
  // 
  // For example, when constructing the config for the following stanza:
  // handler StaticFileHandler {
  //   location /static/;
  //   document_root /foo/bar;
  // }
  // The call to initialize would only contain the config data for the location
  // and the document_root.
  virtual bool Initialize(const NginxConfig& config) = 0;

  // Parses a HTTP request and generates a HTTP response to the request.
  // Returns true if successful.
  virtual bool HandleRequest(const std::string& request,
  	                         std::string* response) = 0;
};