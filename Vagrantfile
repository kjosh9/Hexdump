$bootstrap = <<BOOTSTRAP
export DEBIAN_FRONTEND=noninteractive
apt-get update
apt-get -y install build-essential cmake
BOOTSTRAP

Vagrant.configure("2") do |config|
  config.vm.box = "ubuntu/xenial32"
  
  # setup the VM
  config.vm.provision "shell", inline: $bootstrap
  
end

