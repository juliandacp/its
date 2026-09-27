document.addEventListener("DOMContentLoaded", () => {

    // Theme
    const themeButton = document.getElementById("themeButton");
    const savedTheme = localStorage.getItem("theme");
    if(savedTheme === "dark") document.body.classList.add("dark");
    if(themeButton){
        themeButton.addEventListener("click", () => {
            document.body.classList.toggle("dark");
            const isDark = document.body.classList.contains("dark");
            localStorage.setItem(
                "theme",
                isDark ? "dark" : "light"
            );

        });

    }

    // Mobile Menu
    const hamburger = document.getElementById("hamburger");
    const navLinks = document.getElementById("navLinks");
    if(hamburger && navLinks){
        hamburger.addEventListener("click", () => {
            navLinks.classList.toggle("open");
        });

        const links = navLinks.querySelectorAll(".nav-link");
        links.forEach(link => {
            link.addEventListener("click", () => {
                navLinks.classList.remove("open");
            });
        });
    }


    // Typing Effect
    const typedRole = document.getElementById("typedRole");
    if(typedRole){
        const roles = [
            "Student",
            "Programmer",
            "Technology Enthusiast"
        ];

        let roleIndex = 0;
        let charIndex = 0;
        let deleting = false;

        function typeEffect(){
            const currentRole = roles[roleIndex];
            if(!deleting){
                typedRole.textContent =
                    currentRole.substring(
                        0,
                        charIndex + 1
                    );

                charIndex++;
                if(charIndex === currentRole.length) {
                    deleting = true;
                    setTimeout(
                        typeEffect,
                        1500
                    );
                    return;
                }

            }else{
                typedRole.textContent =
                    currentRole.substring(
                        0,
                        charIndex - 1
                    );

                charIndex--;
                if(charIndex === 0){
                    deleting = false;
                    roleIndex =
                        (roleIndex + 1) %
                        roles.length;
                }
            }

            const speed = deleting ? 45 : 80;
            setTimeout(
                typeEffect,
                speed
            );

        }
        typeEffect();
    }

    //Year
    const year = document.getElementById("year");
    if(year){
        year.textContent =
            new Date().getFullYear();
    }
});