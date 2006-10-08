/*
 * Copyright (c) 2003-2006 Andrea Luzzardi <scox@sig11.org>
 *
 * This file is part of the pam_usb project. pam_usb is free software;
 * you can redistribute it and/or modify it under the terms of the GNU General
 * Public License version 2, as published by the Free Software Foundation.
 *
 * pam_usb is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef PUSB_CONF_H_
# define PUSB_CONF_H_
# define CONF_DEVICE_XPATH "//configuration/devices/device[@id='%s']/%s"
# define CONF_USER_XPATH "//configuration/users/user[@id='%s']/%s"
# define CONF_SERVICE_XPATH "//configuration/services/service[@id='%s']/%s"
# define CONF_USER_MAXLEN 32

typedef struct	pusb_device
{
  char		name[32];
  char		vendor[32];
  char		model[32];
  char		serial[64];
}		t_pusb_device;

typedef struct	pusb_options
{
  int		enable;
  int		try_otp;
  int		enforce_otp;
  int		debug;
  char		hostname[32];
  t_pusb_device	device;
}		t_pusb_options;

struct	s_opt_list
{
  char	*name;
  char	*value;
};

int	pusb_conf_init(t_pusb_options *opts);
int	pusb_conf_parse(const char *file, t_pusb_options *opts,
			const char *user, const char *service);

#endif /* !PUSB_CONF_H_ */
