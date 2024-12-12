build:
	docker build -t ubuntu-disk-image-dear-diary .

run:
	# --privileged is required here to manage loop back devices within the container
	docker run --privileged -it -v ~/code/SecChapter/picoCTF/dear_diary/:/mnt ubuntu-disk-image-dear-diary
