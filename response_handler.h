class NginxConfig;

class ResponseHandler {
 public:
  // Initialize the response handler. The config object is just the portion
  // that applies to the response handler.
  virtual void Initialize(const NginxConfig& config) = 0;

  // Generates response for the request.
  // Returns true if successful. Returns the response in Response object.
  virtual bool HandleRequest(const Request& request, Response* response) = 0;
}
