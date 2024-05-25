#!/usr/bin/env bash

MONITOR_HOME_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )/../.." && pwd )"

#dirname  "${BASH_SOURCE[0]}"
#文件目录

#$( cd "$( dirname "${BASH_SOURCE[0]}" )/../.." && pwd )
#把目录给montior_home_dir, ${montior_home_dir}是目录项


local_host="$(hostname)"


user="${USER}"
#用户名  

uid="$(id -u)"
group="$(id -g -n)"
gid="$(id -g)"


echo "stop and rm docker" 
docker stop safe_udp > /dev/null
docker rm -v -f safe_udp > /dev/null

echo "start docker"
docker run -it -d \
--privileged=true \
--name safe_udp \
-e DOCKER_USER="${user}" \
-e USER="${user}" \
-e DOCKER_USER_ID="${uid}" \
-e DOCKER_GRP="${group}" \
-e DOCKER_GRP_ID="${gid}" \
-v ${MONITOR_HOME_DIR}:/work \
-v ${XDG_RUNTIME_DIR}:${XDG_RUNTIME_DIR} \
--network host \
safe:udp
