
# We're running selenium headless
require 'headless'

headless = Headless.new
headless.start

at_exit do

  headless.destroy
end
