# Filesytem Interactions

Filesystem rules are defined as:

1. Files under the Linux root (i.e. “/”) are controlled by the subsystem.  This allows for Linux specific behavior including but is not limited to:
  * Files which contain invalid Windows filename characters
  * Symlinks created for non-admin users
  * Changing file attributes through chmod and chown
  * Case sensitivity
2. Files not under the Linux root are controlled by Windows:
  * Case insensitivity
  * Cannot create symlinks
  * Files and directories have all permissions (i.e. 777)
3. It is not possible to create a symlink between the two filesystems

Automatically created mount points for hard drives on the local machine provide easy access to the filesystem.  Files in these mount points do not behave as if controlled by the subsystem.
 
**/mnt/\<drive letter>/**
 
Example usage would be `cd /mnt/c` to access c:\
