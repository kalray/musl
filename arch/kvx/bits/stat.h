struct stat {
    dev_t st_dev;			/* Device. */
    ino_t st_ino;			/* 32bit file serial number. */
    mode_t st_mode;			/* File mode.  */
    nlink_t st_nlink;			/* Link count.  */
    uid_t st_uid;			/* User ID of the file's owner.	*/
    gid_t st_gid;			/* Group ID of the file's group.*/
    dev_t st_rdev;			/* Device number, if device.  */
    unsigned long long _pad1;
    off_t st_size;				/* Size of file, in bytes. */
    blksize_t st_blksize;				/* Optimal block size for I/O. */
    int __pad2;
    blkcnt_t st_blocks;			/* Number 512-byte blocks allocated */
    struct timespec st_atim;			/* Time of last access.  */
    struct timespec st_mtim;			/* Time of last modification.  */
    struct timespec st_ctim;			/* Time of last status change.  */
    unsigned int __unused[2];
};
