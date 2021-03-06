
/***************************************************************************
 *                                                                         *
 *                   _        _____               ____                     *
 *           /\     | |      |  __ \      /\     |  _ \      /\            *
 *          /  \    | |      | |  | |    /  \    | |_) |    /  \           *
 *         / /\ \   | |      | |  | |   / /\ \   |  _ <    / /\ \          *
 *        / ____ \  | |___   | |__| /  / ____ \  | |_) /  / ____ \         *
 *       /_/    \_\ | ____|  |_____/  /_/    \_\ |____/  /_/    \_\        *
 *                                                                         *
 *    == {Port Knocking/Single Packet Authorization} Security Suite ==     *
 *                                                                         *
 ***************************************************************************
 *                                                                         *
 * This file is part of Aldaba Knocking Suite.                             *
 *                                                                         *
 * Copyright (c) 2010, Luis MartinGarcia. (aldabaknocking@gmail.com)       *
 *                                                                         *
 * Aldaba is free software; you can redistribute it and/or modify it under *
 * the terms of the GNU General Public License as published by the Free    *
 * Software Foundation; Version 2 of the License, with the exceptions,     *
 * conditions and clarifications described in the file named LICENSE.txt,  *
 * distributed with Aldaba or available from:                              *
 * <http://www.aldabaknocking.com/LICENSE.txt>                             *
 *                                                                         *
 * Aldaba is distributed in the hope that it will be useful, but WITHOUT   *
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or   *
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License   *
 * v2.0 for more details.                                                  *
 *                                                                         *
 * You should have received a copy of the GNU General Public License along *
 * with Aldaba; if not, write to the Free Software Foundation, Inc.,       *
 * 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA                *
 *                                                                         *
 * Please check file LICENSE.txt for the complete version of the license,  *
 * as this disclaimer does not contain the full information. Also, note    *
 * that although Aldaba is licensed under the GNU GPL v2.0 license, it may *
 * be possible to obtain copies of it under different, less restrictive,   *
 * alternative licenses. Requests will be studied on a case by case basis. *
 * If you wish to obtain Aldaba under a different license, please use the  *
 * email address shown above.                                              *
 *                                                                         *
 ***************************************************************************/

#ifndef __SERVER_H__
#define __SERVER_H__ 1
#include "AuthRecord.h"

int main(int argc, char *argv[]);
void server_cleanup(void);
void server_cleanup_signal(int signo);
int script_init();
int script_cleanup();


class Server {

    private:
        vector<AuthRecord *> auth_record;
        vector<AuthRecord *> ssh_auth;

        AuthRecord *auth_record_new(u32 time, u8 *nonce, size_t nonce_len);
        int auth_record_insert(AuthRecord *x);
        int auth_record_purge();

        AuthRecord *ssh_auth_new(u32 time, u8 *nonce, size_t nonce_len);
        int ssh_auth_insert(AuthRecord *x);
        int ssh_auth_purge();

    protected:
        int auth_record_insert_new(u32 time, u8 *nonce, size_t nonce_len);
        int auth_record_remove(AuthRecord *x);
        int auth_record_remove(AuthRecord x);
        AuthRecord *auth_record_lookup(u32 time, u8 *nonce, size_t nonce_len);

        int ssh_auth_insert_new(u32 time, u8 *nonce, size_t nonce_len);
        int ssh_auth_remove(AuthRecord *x);
        int ssh_auth_remove(AuthRecord x);
        AuthRecord *ssh_auth_lookup(u32 time, u8 *nonce, size_t nonce_len);

    public:
        Server();
        ~Server();
        void reset();

        int init();
        void print_banner();
        void print_conf();
        static void test_stuff(int argc, char *argv[]);

}; /* End of class Server */

#endif /* __SERVER_H__ */
