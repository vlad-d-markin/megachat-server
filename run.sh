#!/bin/sh

########################################
# This is shell script that can perform build operations.
########################################

COMMAND=$1
ROOT_DIR=$(pwd)

BUILD_DIR=$ROOT_DIR/build
PKG_DIR=$ROOT_DIR/pkg
INSTALLATION_FILES=$ROOT_DIR/installation


########################################
# Help message
########################################
print_help () {
	echo 
	echo "Usage: ./run.sh [build|build-package|install|remove|clean|full-clean|help]"
	echo "	build 		-- build application from source code"
	echo "	build-package 	-- build rpm package"
	echo "	install 	-- install application"
	echo "	install-pkg 	-- install application from package"
	echo "	remove 		-- uninstall application"
	echo "	clean 		-- clean build directory"
	echo "	full-clean 	-- remove all build files and packages"
	echo
}



########################################
# Build source code
########################################
build_source () {
	if ! [ -d $BUILD_DIR ] ; then
		mkdir $BUILD_DIR
	fi

	cd $BUILD_DIR	
	cmake .. && make
	cd $ROOT_DIR
}



########################################
# Perform make clean 
########################################
clean () {
	cd $BUILD_DIR	
	make clean
	cd $ROOT_DIR
	
}



########################################
# Wipe build files
########################################
full_clean () {
	rm -rf $BUILD_DIR/*
}



########################################
# Install from build dir
########################################
install_app () 
{
echo
}


########################################
# Remove app
########################################
remove_app () 
{
echo
}


########################################
# Parse command
########################################
case "${COMMAND}" in
	"help" )
		print_help
	;;
	"build" )
		echo "Building..."
		build_source
	;;
	"build-package" )
		echo "Building package..."
	;;
	"install" )
		echo "Installing..."
		install_app
	;;
	"install-pkg" )
		echo "Installing package..."
	;;
	"remove" )
		echo "Removing..."
		remove_app
	;;
	"clean" )
		echo "Cleaning build dir..."
		clean
	;;
	"full-clean" )
		echo "Wiping build dir..."
		full_clean
	;;
	* )
		print_help
	;;
esac
