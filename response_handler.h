class NginxConfig;

class ResponseHandler {
 public:
  virtual void Initialize(const NginxConfig& config) = 0;
  virtual Response HandleRequest(const Request& request) = 0;
}
