---
aliases:
context:
- "[[Containerization]]"
---

# Docker

Docker is a tool for creating, running, and manipulating containers.

---
A *container* is like a lightweight, portable mini-computer (or mini-OS) that runs your app - with *all its dependencies bundled in*. This means it works *exactly the same* everywhere: on your laptop, your colleague's machine, or a cloud server.

It is different from a VM by being lightweight, boots in seconds, shares the same OS as its host, and the performance is near-native.

### Key concepts:
- Image - A snapshot of a container (like a template). You can think of it like a class in OOP.
- Container - A running instance of an image (like an object)
- Dockerfile - A script that defines how to build an image (what OS, what to install, etc.)
 - Docker Hub - A public registry where you can download prebuilt images (like Ubuntu, Node.js, MySQL, etc.)

### Common use cases:
- running services like PostgreSQL, Redis, or Nginx
- creating isolated dev envs
- deploying microservices
- running different app versions side by side


Example *Dockerfile* for a Node.js app:
``` dockerfile
FROM node:18
WORKDIR /app
COPY . .
RUN npm install
CMD ["npm", "start"]
```

then you'd build it like:

``` docker
docker build -t my-app .
docker run -p 3000:3000 my-app
```