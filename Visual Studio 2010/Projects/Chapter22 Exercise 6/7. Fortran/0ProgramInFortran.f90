!TITLE          Projectile Motion                      ProjectileMotion.f90
!    Fortran for Science and Engineering
!COMMENT
!   Objective: Compute the position (x and y co-ordinates) and the velocity
!              (magnitude and direction) of a projectile, given t,
!              the time since launch, u, the launch velocity, a, the
!              initial angle of launch (in degrees), and g,
!              the acceleration due to gravity.
!       Input: -
!      Output: -
!      Author: Chris B. Kirov
!        Date: 31.03.20

program ProjectileMotion
    implicit none

    ! Constants !
    real, parameter :: PI = 3.1415927               ! pi
    real, parameter :: g = 9.81                     ! acceleration due to gravity

    ! Initial conditions !
    real a                                          ! launch angle in degrees
    real u                                          ! launch velocity
    real t                                          ! time of flight

    ! Wanted values !
    real theta                                      ! direction at time t in degrees
    real x                                          ! horizontal displacement
    real y                                          ! vertical displacement
    real vx                                         ! horizontal velocity
    real vy                                         ! vertical velocity
    real v                                          ! resultant velocity

    ! Read input !
    print *, "Type launch angle [degrees]:"
    read *, a

    print *, "Type launch velocity [m/s]:"
    read *, u

    print *, "Type time of flight [s]:"
    read *, t

    ! Calculate wanted values !
    a = a * PI / 180.                               ! convert to radians

    x = u * cos(a) * t
    y = u * sin(a) * t  - g * t * t / 2.0

    vx = u * cos(a)
    vy = u * sin(a) - g * t

    v = sqrt(vx * vx + vy * vy)
    theta = tan(vy / vx) * 180 / PI                 ! directly converted in degrees

    ! Print results !
    print *, "Horizontal displacement, x: ", x, "Vertical displacement, y: ", y
    print *, "Horizontal velocity, Vx: ", vx, "Vertical velocity, Vy: ", vy
    print *, "Resultant velocity magnitude, V: ", v, "Resultant Velocity Direction, Theta: ", theta
end program ProjectileMotion
